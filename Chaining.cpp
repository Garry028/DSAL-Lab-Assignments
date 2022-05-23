#include <iostream>
#include <bits/stdc++.h>
#include <string>
#define MAXX 10
using namespace std;

class Dict_ADT;
class Data_Node
{
private:
    string word;
    string mean;
    Data_Node *next;

public:
    Data_Node()
    {
        word = "";
        mean = "";
        next = NULL;
    }
    Data_Node(string word, string mean)
    {
        this->word = word;
        this->mean = mean;
        next = NULL;
    }
    friend class Dict_ADT;
};
class Dict_ADT
{
    Data_Node *HT[MAXX]; // this is pointer array of object
private:
    int index;

public:
    Dict_ADT()
    {
        for (int i = 0; i < 10; i++)
        {
            HT[i] = NULL;
        }
    }
    int HashFunction(string);
    void Insert(string, string);
    void Search(string);
    void Delete(string);
    void Display();
};
int Dict_ADT::HashFunction(string word)
{
    int key = 0;
    for (int i = 0; i < word.length(); i++)
    {
        key = key + (int)word[i];
    }
    cout << key << " will be go into hash function " << endl;
    // Here we've taken a string then taken the sum of ascii value of each character in the word then hashed that sum
    return key % MAXX;
}
void Dict_ADT::Insert(string word, string mean)
{
    int index = HashFunction(word); // here word will get hashed and wi'll get the index
    Data_Node *pTemp, *pNew;
    pNew = new Data_Node(word, mean);

    if (HT[index] == NULL)
    {
        HT[index] = pNew;
        // if no node is there insert new
    }
    else
    {
        cout << "Collision occured" << endl;
        pTemp = HT[index];
        while (pTemp->next != NULL)
        {
            pTemp = pTemp->next;
        }
        pTemp->next = pNew; // next will become new node
    }
    cout << "Record inserted !!" << endl;
}
void Dict_ADT::Search(string word)
{
    Data_Node *pTemp;
    bool s_success = 0;
    int index = HashFunction(word);
    if (HT[index]->word == word)
    {
        cout << "Data Found " << endl;
        cout << "Word & Meaning is:\n "
             << HT[index]->word << endl
             << HT[index]->mean << endl;
    }
    else
    {
        pTemp = HT[index];
        while (pTemp->next != NULL)
        {
            pTemp = pTemp->next;
            if (pTemp->word == word)
            {
                cout << "Data Found " << endl;
                cout << "Word: " << pTemp->word << endl;
                cout << "Meaning: " << pTemp->mean << endl;
                s_success = 1;
                break;
            }
        }
        if (s_success == 0)
        {
            cout << "Word Not Found !!" << endl;
        }
    }
}
void Dict_ADT::Delete(string word)
{
    Data_Node *pTemp, *prev;
    int index = HashFunction(word);
    if (HT[index]->word == word)
    {
        cout << HT[index]->word << " is deleted !!" << endl;
        HT[index] = HT[index]->next;
    }
    else
    {
        pTemp = HT[index]->next;
        prev = HT[index];
        while (pTemp != NULL)
        {
            if (pTemp->word == word)
            {
                cout << pTemp->word << " is deleted" << endl;
                prev->next = pTemp->next;
                pTemp->next = NULL;
                break;
            }
            pTemp = pTemp->next;
            prev = prev->next;
        }
    }
}
void Dict_ADT::Display()
{
    Data_Node *pTemp;
    cout << "Dictionary is: " << endl;
    for (int i = 0; i < MAXX; i++)
    {
        pTemp = HT[i];
        cout << i << "-->";
        while (pTemp != NULL)
        {
            cout << "[ " << pTemp->word << " , " << pTemp->mean << " ] -- ";

            pTemp = pTemp->next;
        }
        cout << endl;
    }
}

int main()
{
    Dict_ADT d;
    bool flag = true;
    int choice;
    string word, mean;
    while (flag)
    {
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the word that you want insert: " << endl;
            getline(cin >> ws, word);
            cout << "Enter the meaning of word: " << endl;
            getline(cin >> ws, mean);
            d.Insert(word, mean);
            break;
        case 2:
            cout << "Enter the word that you want to delete " << endl;
            cin >> word;
            d.Delete(word);
            break;
        case 3:
            cout << "Enter the word that you want to search " << endl;
            cin >> word;
            d.Search(word);
            break;
        case 4:
            d.Display();
            break;
        case 5:
            exit(0);
        }
        char flag2;
        cout << "Do you want to continue ? " << endl;
        cin >> flag2;
    }

    return 0;
}
