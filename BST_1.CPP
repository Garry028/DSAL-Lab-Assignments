#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
private:
    int data;

    Node *left;
    Node *right;

public:
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }

    friend class BST;
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    void insert(int value)
    {
        Node *pNew, pTemp;
        pNew = new Node(value);
        if (root == NULL)
        {
            root = pNew;
            cout << "root created" << endl;
        }
        else
        {
            Node *pTemp = root;
            do
            {
                if (pTemp->data > value)
                {
                    if (pTemp->left == NULL)
                    {
                        pTemp->left = pNew;
                        cout << "Value added at left subtree " << endl;
                        break;
                    }
                    else
                    {
                        pTemp = pTemp->left;
                    }
                }
                else if (pTemp->data < value)
                {
                    if (pTemp->right == NULL)
                    {
                        pTemp->right = pNew;
                        cout << "Value added at right end subtree " << endl;

                        break;
                    }
                    else
                    {
                        pTemp = pTemp->right;
                    }
                }
                else
                {
                    cout << "Duplicate value !" << endl;
                    break;
                }
            } while (pTemp != NULL);
        }
    }
    void inordertraversal()
    {
        stack<Node *> st;
        Node *pTemp = root;
        do
        {
            while (pTemp != NULL)
            {
                st.push(pTemp);
                pTemp = pTemp->left;
            }
            if (!st.empty())
            {
                pTemp = st.top();
                st.pop();
                cout << pTemp->data << " ";
                pTemp = pTemp->right;
            }

        } while (!st.empty() || pTemp != NULL);
    }
    Node *Minimum(Node *root)
    {
        Node *pTemp = root;
        if (pTemp->left == NULL)
        {
            return root;
        }
        else
        {
            return Minimum(pTemp->left); // BECAUSE OF THIS IT WILL GO TO LAST ELEMENT
        }
    }
    Node *Maximum(Node *root)
    {
        Node *pTemp = root;
        if (pTemp->right == NULL)
        {
            return root;
        }
        else
        {
            return Maximum(pTemp->right);
        }
    }
    void display_min_max()
    {
        Node *pTemp1, *pTemp2;
        pTemp1 = Minimum(root);
        pTemp2 = Maximum(root);
        cout << "Minimum element is " << pTemp1->data << endl;
        cout << "Maximum element is " << pTemp2->data;
    }
    Node *predecessor(Node *root)
    {
        // rightmost child of left subtree
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }
    Node *successor(Node *root)
    {
        // leftmost child of right subtree
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }
    Node *Delete_val(Node *root, int val)
    {
        // rightmost child of left subtree
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            if (val < root->data)
            {
                root->left = Delete_val(root->left, val);
            }
            else if (val > root->data)
            {
                root->right = Delete_val(root->right, val);
            }
            else // Data Found
            {
                if (root->right == NULL)
                {
                    return root->left;
                }
                else
                {
                    Node *isuc = successor(root->right);
                    root->data = isuc->data; // copy the element
                    root->right = Delete_val(root->right, isuc->data);
                }
            }
            return root;
        }
    }

    void jockey(int key)
    {
        root = Delete_val(root, key);
    }

    int Height(Node *root)
    {
        if (root == NULL)
            return 0;
        int lh = Height(root->left);
        int rh = Height(root->right);
        return lh > rh ? lh + 1 : rh + 1;
    }
    void height_display()
    {
        cout << "Height is " << Height(root) << endl;
    }

    int diameter(Node *root)
    {
        if (root = NULL)
            return 0;

        int lh = Height(root->left);
        int rh = Height(root->right);

        int currDiameter = lh + rh + 1;

        int ld = diameter(root->left);
        int rd = diameter(root->right);

        return max(currDiameter, max(ld, rd));
    }
    int diameter_display()
    {
        cout << "Diameter is " << diameter(root);
    }
    void swap(Node *root)
    {
        Node *pTemp;
        if (root->left != NULL)
            swap(root->left);
        if (root->right != NULL)
            swap(root->right);

        pTemp = root->left;
        root->left = root->right;
        root->right = pTemp;
    }
    void display_swap()
    {
        cout <<"BST after swapping is ";
        swap(root);
    }
  
};
int main()
{
    BST b;
    int n, data;
    cout << "How many nodes do you want?" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value that you want to insert" << endl;
        cin >> data;
        b.insert(data);
    }
    cout << "Inorder Traversal is ";
    b.inordertraversal();
    cout << endl;
    b.display_min_max();
    cout << endl;
    b.height_display();
    b.display_swap();
    b.inordertraversal();
}