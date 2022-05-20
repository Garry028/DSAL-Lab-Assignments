#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
private:
    string word, meaning;
    Node *left;
    Node *right;

public:
    Node()
    {
        word = " ";
        meaning = " ";
        left = NULL;
        right = NULL;
    }

    Node(string value, string mean)
    {
        word = value;
        meaning = mean;
        left = NULL;
        right = NULL;
    }

    friend class BST_Dict;
};

class BST_Dict
{
private:
    Node *root;

public:
    BST_Dict()
    {
        root = NULL;
    }

    void root_creation(string value, string mean)
    {
        Node *pNew, pTemp;
        pNew = new Node(value, mean);
        if (root == NULL)
        {
            root = pNew;
            cout << "root created" << endl;
        }
    }

    void insert(string value, string mean)
    {
        Node *pNew, pTemp;
        pNew = new Node(value, mean);
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
                if (pTemp->word > value)
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
                else if (pTemp->word < value)
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
                cout << pTemp->word << "-->" << pTemp->meaning << " " << endl;
                pTemp = pTemp->right;
            }

        } while (!st.empty() || pTemp != NULL);
    }
    // Node *Minimum(Node *root)
    // {
    //     Node *pTemp = root;
    //     if (pTemp->left == NULL)
    //     {
    //         return root;
    //     }
    //     else
    //     {
    //         return Minimum(pTemp->left);
    //     }
    // }
    // void display_minimum()
    // {
    //     Node *pTemp;
    //     pTemp = Minimum(root);
    //     cout << "Minimum element is " << pTemp->word << endl;
    // }

    Node *Search(Node *root, string Key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->word == Key)
        {
            return root;
        }
        else if (root->word > Key)
        {
            return Search(root->left, Key);
        }
        else
        {
            return Search(root->right, Key);
        }
    }
    void Jockey_Search(string key)
    {
        root = Search(root, key);
        cout << root->word << " meaning of this word is " << root->meaning << endl;
    }

    Node *predecessor(Node *root)
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }
    Node *successor(Node *root)
    {

        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }
    Node *Delete_val(Node *root, string val)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            if (val < root->word)
            {
                root->left = Delete_val(root->left, val);
            }
            else if (val > root->word)
            {
                root->right = Delete_val(root->right, val);
            }
            else // word Found
            {
                if (root->right == NULL)
                {
                    return root->left;
                }
                else
                {
                    Node *iPre;
                    iPre = successor(root->right);
                    root->word = iPre->word;
                    root->right = Delete_val(root->right, iPre->word);
                }
            }
            return root;
        }
    }
    void jockey(string key)
    {
        root = Delete_val(root, key);
    }

    void replace()
    {
        string wrd, Nwrd, mn;
        cout << "Enter the word that you want to replace" << endl;
        getline(cin >> ws, wrd);
        root = Delete_val(root, wrd);
        cout << "Enter the new word that you want to insert" << endl;
        getline(cin >> ws, Nwrd);
        cout << "enter the meaning of new word" << endl;
        getline(cin >> ws, mn);
        insert(Nwrd, mn);
        inordertraversal();
    }
};

int main()
{
    BST_Dict b;
    int n;
    string key, word, meaning;
    int choice;
    bool flag = true;
    cout << "Welcome to the Dictionary !!!!" << endl;
    cout << "What do you want to do??" << endl;
    while (flag)
    {
        cout << "1.Create a Dictionary\n2.Insert into the dictionary\n3.Search a word\n4.Delete a word\n5.Update the word\n6.Display in ascending\nSelect an Option" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            Node *root;

            cout << "Enter the word that you want to insert" << endl;
            getline(cin >> ws, word);
            cout << "Enter the meaning of the word that you want to insert" << endl;
            getline(cin >> ws, meaning);
            b.insert(word, meaning);
            break;
        case 2:
            cout << "Enter the word that you want to insert" << endl;
            getline(cin >> ws, word);
            cout << "Enter the meaning of the word that you want to insert" << endl;
            getline(cin >> ws, meaning);
            b.insert(word, meaning);
            break;
        case 3:

            cout << "Which word's meaning do you want to search" << endl;
            getline(cin >> ws, key);
            b.Jockey_Search(key);
            break;
        case 4:
            cout << "enter the word u want to delete" << endl;
            getline(cin >> ws, key);

            break;
        case 5:
            b.replace();
            break;
        case 6:
            b.inordertraversal();
            break;
        default:
            break;
        }
        char flag2;
        cout << "Do you want to continue(y or n) :" << endl;
        cin >> flag2;
        if (flag2 == 'n')
        {
            flag = false;
        }
    }
}
