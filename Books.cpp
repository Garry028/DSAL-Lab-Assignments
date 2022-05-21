/*
A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print the nodes. Find the time and space requirements
of your method.
*/
#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
class GT;
class Node
{
private:
    char label[20];
    int ch_count;
    Node *child[10];

public:
    friend class GT;
};

class GT
{
private:
    Node *root;

public:
    void create_tree();
    void display(Node *r1);
    void Display_Jockey();

    GT()
    {
        root = NULL;
    }
};

void GT::create_tree()
{
    int tbooks, tchapters, i, j, k;
    root = new Node;
    cout << "Enter name of book : ";
    cin >> root->label;
    cout << "Enter number of chapters in book :";
    cin >> tchapters;
    root->ch_count = tchapters;
    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new Node;
        cout << "Enter chapter " << i + 1 << " name: \n";
        cin >> root->child[i]->label;
        cout << "Enter no. of sections in chapter " << root->child[i]->label << "\n";
        cin >> root->child[i]->ch_count;

        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new Node;
            cout << "Enter section " << j + 1 << "name: \n";
            cin >> root->child[i]->child[j]->label;
        }
    }
}

void GT::display(Node *r1)
{
    int i, j, k, tchapters;
    if (r1 != NULL)
    {
        cout << "\n-----book hierarchy ----";
        cout << "\n Book title  : " << r1->label;
        tchapters = r1->ch_count;
        for (i = 0; i < tchapters; i++)
        {
            cout << "\n Chapter : " << i + 1;
            cout << "" << r1->child[i]->label;
            cout << "\n sections : ";
            for (j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout << "\n " << r1->child[i]->child[j]->label;
            }
        }
    }
}

void GT::Display_Jockey()
{
    display(root);
}

int main()
{
    int choice;
    GT gt;
    while (1)
    {
        cout << "------------" << endl;
        cout << "Book Tree Creation " << endl;
        cout << "-------" << endl;
        cout << "1.Create" << endl;
        cout << "2.Display" << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            gt.create_tree();
            break;
        case 2:
            gt.Display_Jockey();
            break;
        case 3:
            exit(1);
        default:
            cout << " wrong choice " << endl;
        }
    }
}
