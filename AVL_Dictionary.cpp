#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class AVL;
class Node
{
private:
    string Word, Meaning;
    Node *left;
    Node *right;

public:
    Node()
    {
        Word = "";
        Meaning = "";
        left = NULL;
        right = NULL;
    }
    Node(string wrd, string mean)
    {
        Word = wrd;
        Meaning = mean;
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
    Node *Insert(Node *root, string word, string mean);
    void Ascending(Node *root);
    void Dscending(Node *root);
    void Display_Insert(string word, string mean);
    void Display_Preorder();
    void Display_Ascending();
    Node *Search(Node *root, string word,int count);
    void Display_Search(string word);
    Node *Delete(Node *root, string word);
    void Display_Delete(string word);
    Node *succesor(Node *root);
    void Update_Word();
    Node *Minimum(Node *root);
    Node *Maxximum(Node *root);
    void Display_Min_Maxx();
};
Node *AVL::Minimum(Node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    while (root->left != NULL)
    {
        return Minimum(root->left);
    }
}
Node *AVL::Maxximum(Node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    while (root->right != NULL)
    {
        return Minimum(root->right);
    }
}

void AVL::Display_Min_Maxx()
{
    Node *pTemp1, *pTemp2;
    pTemp1 = Minimum(root);
    pTemp2 = Maxximum(root);
    cout << "Minimum element is " << pTemp1->Word << endl;
    cout << "Maximum element is " << pTemp2->Word << endl;
}
void AVL::Update_Word()
{
    string wrd, Nwrd, mn;
    cout << "Enter the word that you want to replace" << endl;
    getline(cin >> ws, wrd);
    root = Delete(root, wrd);
    cout << "Enter the new word that you want to insert" << endl;
    getline(cin >> ws, Nwrd);
    cout << "Enter the meaning of new word" << endl;
    getline(cin >> ws, mn);
    root = Insert(root, Nwrd, mn);
    cout << "Word has been updated " << endl;
}
Node *AVL::succesor(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
void AVL::Display_Ascending()
{
    Ascending(root); // inorder means ascending.
}
void AVL::Display_Preorder()
{
    Dscending(root);
}
void AVL ::Display_Insert(string word, string mean)
{
    root = Insert(root, word, mean);
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
Node *AVL::Insert(Node *root, string word, string mean)
{
    Node *pNew = new Node(word, mean);
    if (root == NULL)
    {
        root = pNew;
        return root;
    }
    if (word < root->Word)
    {
        root->left = Insert(root->left, word, mean);
    }
    if (word > root->Word)
    {
        root->right = Insert(root->right, word, mean);
    }
    if (word == root->Word)
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
    Node *PR = root->right;
    Node *PR_L = PR->left;

    PR->left = PR_L->right;
    root->right = PR_L->left;

    PR_L->left = root;
    PR_L->right = PR;
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
void AVL ::Ascending(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Ascending(root->left);
    cout << root->Word << " --> " << root->Meaning << endl;
    Ascending(root->right);
}

void AVL ::Dscending(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Dscending(root->right);
    cout << root->Word << " --> " << root->Meaning << endl;
    Dscending(root->left);
}
Node *AVL::Delete(Node *root, string word)
{

    // rightmost child of left subtree->succesor
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (word < root->Word)
        {
            root->left = Delete(root->left, word);
        }

        else if (word > root->Word)
        {
            root->right = Delete(root->right, word);
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
                root->Word = isuc->Word; // copy the element
                root->right = Delete(root->right, isuc->Word);
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

void AVL::Display_Delete(string word)
{
    root = Delete(root, word);
}
Node *AVL::Search(Node *root, string word,int count)
{
    count++;
    if (root == NULL)
    {
        return NULL;
    }
    if (word == root->Word)
    {
        cout << "Value present in tree" << endl;
        cout<<"Total comparison are "<<count<<endl;
        return root;
    }
    else if (word < root->Word)
    {
        root->left = Search(root->left, word,count
        );
    }
    else
    {
        root->right = Search(root->right, word,count);
    }
}
void AVL::Display_Search(string word)
{

    root = Search(root, word,0);
}
int main()
{
    AVL a;
    bool flag = true;
    string Word, key_word, mean;
    int choice;
    while (flag)
    {
        cout << "Welcome to Dictionary !!!" << endl;
        cout << "___________________________________________\n"
             << endl;
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Ascending Order\n5.Dscending order\n6.Update\n7.Min_Max\n"
             << endl;
        cout << "___________________________________________\n"
             << endl;

        cout << "What do you want to do ?" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int n;
            cout << "How many nodes do you want?" << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the value that you want to insert" << endl;
                getline(cin >> ws, key_word);
                cout << "Enter the meaning of that word " << endl;
                getline(cin >> ws, mean);
                a.Display_Insert(key_word, mean);
            }
            break;
        case 2:
            cout << "Enter the key_word that you want to Delete " << endl;
            cin >> key_word;
            a.Display_Delete(key_word);
            break;
        case 3:
            cout << "Enter the key_word that you want to Search " << endl;
            cin >> key_word;
            a.Display_Search(key_word);
            break;
        case 4:
            cout << "Ascending order is: " << endl;
            a.Display_Ascending();
            break;
        case 5:
            cout << "Descending order is: " << endl;
            a.Display_Preorder();
            break;

        case 6:
            a.Update_Word();
            break;

        case 7:
            a.Display_Min_Maxx();
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
