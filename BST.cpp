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
        cout << "Empty BST created" << endl;
    }
    void insert(int value);
    void heightjockey();
    int Height(Node *root);
    // Node *insert_rec(Node *root, int value)
    // {
    //     Node *pNew = new Node(value);
    //     if (root == NULL)
    //     {
    //         root = pNew;
    //         cout << "Root created ";
    //     }
    //     if (value < root->data)
    //     {
    //         root->left = insert_rec(root->left, value);
    //     }
    //     else if(value > root->data)
    //     {
    //         root->left = insert_rec(root->left, value);
    //     }
    //     return root;
    // }

    // void jockey_insert(int value)
    // {
    //     root = insert_rec(root, value);
    // }

    Node *Search(Node *root, int key)
    {
        Node *pTemp;
        pTemp = root;
        if (pTemp == NULL)
        {
            cout << "tree not created" << endl;
        }
        else
        {
            while (pTemp != NULL)
            {
                if (key == pTemp->data)
                {
                    cout << "\nThe " << pTemp->data << " Element is present ";
                    break;
                }
                if (key < pTemp->data)
                {
                    pTemp = pTemp->left;
                }
                else
                {
                    pTemp = pTemp->right;
                }
            }
        }
        return NULL;
    }

    void Jockey(int value)
    {
        // root = Search(root, value);
        root = Search(root, value);
    }
};
void BST ::heightjockey()
{
    cout << "Height is " << Height(root);
}

void BST::insert(int value)
{
    Node *pNew;
    pNew = new Node(value);
    pNew->data = value;
    if (root == NULL)
    {
        root = pNew;
        cout << "Root created" << endl;
    }
    else
    {
        Node *pTemp;
        pTemp = root;
        do
        {
            if (value < pTemp->data)
            {
                if (pTemp->left == NULL)
                {
                    pTemp->left = pNew;
                    cout << "\nNew value inserted in left of " << pTemp->data << endl;
                    break;
                }
                else
                {
                    pTemp = pTemp->left;
                }
            }
            else if (value > pTemp->data)
            {
                if (pTemp->right == NULL)
                {
                    pTemp->right = pNew;
                    cout << "\nNew value inserted in right of " << pTemp->data << endl;
                    break;
                }
                else
                {
                    pTemp = pTemp->right;
                }
            }
            else
            {
                cout << "\nDuplicate Value Found" << endl;
                break;
            }

        } while (pTemp != NULL);
    }
}

int BST::Height(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        int lh = Height(root->left);
        int rh = Height(root->right);
        return lh > rh ? lh + 1 : rh + 1;
    }
}

int main()
{
    BST b;
    int n, data;

    cout << "how many nodes do you want?" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cout << "enter the value that you want to insert" << endl;
        cin >> data;
        b.insert(data);
        // b.jockey_insert(data);
    }
    // b.heightjockey();
    b.Jockey(5);

    return 0;
}
