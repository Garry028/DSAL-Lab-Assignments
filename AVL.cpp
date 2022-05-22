// This is not lab assignment beacause it is not dictionary it's just implementation of AVL tree with all it's operation.
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class AVL;
class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    friend class AVL;
};
class AVL
{
private:
    Node *root;

public:
    AVL()
    {
        root = NULL;
    }
    int Height(Node *root);
    int BalanceFactor(Node *root);
    Node *LL_Rotation(Node *root);
    Node *RR_Rotation(Node *root);
    Node *RL_Rotation(Node *root);
    Node *LR_Rotation(Node *root);
    Node *Insert(Node *root, int value);
    void InOrder(Node *root);
    void PreOrder(Node *root);
    void Display_Insert(int value);
    void Display_Preorder();
    void Display_Inorder();
    Node *Search(Node *root, int value);
    void Display_Search(int value);
    Node *Delete(Node *root, int value);
    void Display_Delete(int value);
    Node *succesor(Node *root);
};
Node *AVL::succesor(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
void AVL::Display_Inorder()
{
    InOrder(root);
}
void AVL::Display_Preorder()
{
    PreOrder(root);
}
void AVL ::Display_Insert(int value)
{
    root = Insert(root, value);
}
int AVL::Height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int lh = Height(root->left);
    int rh = Height(root->right);
    return lh > rh ? (lh + 1) : (rh + 1);
}
int AVL::BalanceFactor(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int lh = Height(root->left);
    int rh = Height(root->right);
    return lh - rh;
}
Node *AVL::Insert(Node *root, int value)
{
    Node *pNew = new Node(value);
    if (root == NULL)
    {
        root = pNew;
        return root;
    }
    if (value < root->data)
    {
        root->left = Insert(root->left, value);
    }
    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    if (value == root->data)
    {
        cout << "value already there";
        return root;
    }
    if (BalanceFactor(root) == 2 && BalanceFactor(root->left) == 1)
    {
        cout << "LL Rotation" << endl;
        return LL_Rotation(root);
    }
    else if (BalanceFactor(root) == -2 && BalanceFactor(root->right) == -1)
    {
        cout << "RR Rotation" << endl;
        return RR_Rotation(root);
    }
    else if (BalanceFactor(root) == -2 && BalanceFactor(root->right) == 1)
    {
        cout << "RL Rotation" << endl;
        return RL_Rotation(root);
    }
    else if (BalanceFactor(root) == 2 && BalanceFactor(root->right) == -1)
    {
        cout << "LR Rotation" << endl;
        return LR_Rotation(root);
    }

    return root;
}
Node *AVL::LL_Rotation(Node *root)
{
    Node *PL = root->left;
    Node *PL_R = PL->right;

    PL->right = root;
    root->left = PL_R;
    return PL;
}
Node *AVL::RR_Rotation(Node *root)
{
    Node *PR = root->right;
    Node *PR_L = PR->left;

    PR->left = root;
    root->right = PR_L;
    return PR;
}
Node *AVL::RL_Rotation(Node *root)
{
    Node*PR=root->right;
    Node*PR_L=PR->left;

    PR->left=PR_L->right;
    root->right=PR_L->left;
    
    PR_L->left=root;
    PR_L->right=PR;
    return PR_L;
}
Node *AVL::LR_Rotation(Node *root)
{
    Node *PL = root->left;
    Node *PL_R = PL->right;

    PL->right = PL_R->left;
    root->left = PL_R->right;

    PL_R->left = PL;
    PL_R->right = root;
    return PL_R;
}
void AVL ::InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void AVL ::PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
Node *AVL::Delete(Node *root, int value)
{

    // rightmost child of left subtree->succesor
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (value < root->data)
        {
            root->left = Delete(root->left, value);
        }

        else if (value > root->data)
        {
            root->right = Delete(root->right, value);
        }
        else // Data Found
        {
            if (root->right == NULL)
            {
                return root->left;
            }
            else
            {
                Node *isuc = succesor(root->right);
                root->data = isuc->data; // copy the element
                root->right = Delete(root->right, isuc->data);
            }
        }
    }
    if (BalanceFactor(root) == 2 && BalanceFactor(root->left) == 1)
    {
        cout << "LL Rotation" << endl;
        return LL_Rotation(root);
    }
    else if (BalanceFactor(root) == -2 && BalanceFactor(root->right) == -1)
    {
        cout << "RR Rotation" << endl;
        return RR_Rotation(root);
    }
    else if (BalanceFactor(root) == -2 && BalanceFactor(root->right) == 1)
    {
        cout << "RL Rotation" << endl;
        return RL_Rotation(root);
    }
    else if (BalanceFactor(root) == 2 && BalanceFactor(root->right) == -1)
    {
        cout << "LR Rotation" << endl;
        return LR_Rotation(root);
    }

    return root;
}

void AVL::Display_Delete(int value)
{
    root = Delete(root, value);
}
Node *AVL::Search(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (value == root->data)
    {
        cout << "Value present in tree" << endl;
        return root;
    }
    else if (value < root->data)
    {
        root->left = Search(root->left, value);
    }
    else
    {
        root->right = Search(root->right, value);
    }
}
void AVL::Display_Search(int value)
{
    root = Search(root, value);
}
int main()
{
    AVL a;
    bool flag = true;
    int choice;
    while (flag)
    {
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n"
             << endl;
        cout << "What do you want to do ?" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int n, data, key;
            cout << "How many nodes do you want?" << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the value that you want to insert" << endl;
                cin >> data;
                a.Display_Insert(data);
            }
            break;
        case 2:
            cout << "Enter the key that you want to Delete " << endl;
            cin>>key;
            a.Display_Delete(key);
            break;
        case 3:
            cout << "Enter the key that you want to Search " << endl;
            cin>>key;
            a.Display_Search(key);
            break;
        case 4:
            cout << "Inorder Traversal is: " << endl;
            a.Display_Inorder();
            break;
        case 5:
            cout << "Preorder Traversal is: " << endl;
            a.Display_Preorder();
            break;
        }
        char flag2;
        cout << "\nDo you want to continue ";
        cin >> flag2;
        if (flag2 == 'n')
        {
            flag = false;
        }
    }

    return 0;
}
