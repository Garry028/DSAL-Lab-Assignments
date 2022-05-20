#include <iostream>
#include <iomanip>
using namespace std;

class node
{
    int key;
    string meaning;
    node *left, *right;
    int height;

public:
    node()
    {
        left = right = NULL;
        height = 1;
        meaning = "";
        key = -1;
    }
    node(int key, string meaning)
    {
        this->key = key;
        this->meaning = meaning;
        left = right = NULL;
        height = 1;
    }
    void print()
    {
        cout << endl
             << setw(10) << key << setw(10) << meaning;
    }
    friend class Dictionary;
};
class Dictionary
{
    node *root;

public:
    Dictionary()
    {
        root = NULL;
    }
    int max(int, int);
    int getheight(node *);
    node *insert(node *rnode, int key, string meaning);
    void insertInit(int key, string meaning);
    node *rightRotate(node *);
    node *leftRotate(node *);
    int getbalance(node *);
    void preorder();
    void preorderRec(node *);
    void postorder();
    void postorderRec(node *);
    void inorder();
    void inorderRec(node *);
    void postorder_dec();
    void postorder_dec(node *);
};
int Dictionary::max(int a, int b)
{
    return (a > b) ? a : b;
}
int Dictionary::getheight(node *nnode)
{
    if (nnode == NULL)
        return 0;
    else
        return nnode->height;
}
int Dictionary::getbalance(node *n)
{
    if (n == NULL)
        return 0;
    else
        return (getheight(n->left) - getheight(n->right));
}
node *Dictionary::rightRotate(node *y)
{
    node *x = y->left;
    node *xr = x->right;

    // Update Pointers after rotation
    x->right = y;
    y->left = xr;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    return x;
}

node *Dictionary::leftRotate(node *y)
{
    node *x = y->right;
    node *t2 = x->left;

    x->left = y;
    y->right = t2;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    return x;
}

node *Dictionary::insert(node *rnode, int key, string meaning)
{
    // 1. Normat BST Operation
    if (rnode == NULL) // Empty Dictionary
        return new node(key, meaning);

    if (key < rnode->key)
        rnode->left = insert(rnode->left, key, meaning);
    else if (key > rnode->key)
        rnode->right = insert(rnode->right, key, meaning);
    else // equal value key
        return rnode;

    // 2. update height of ancestors
    rnode->height = 1 + max(getheight(rnode->left), getheight(rnode->right));
    // 3. Get balancing factor
    int balance = getbalance(rnode);

    // 4. perform rotations and return nre root
    // LL Case
    if (balance > 1 && key < rnode->left->key)
        return rightRotate(rnode);

    // RR Case
    if (balance < -1 && key > rnode->right->key)
        return leftRotate(rnode);

    // LR Case
    if (balance > 1 && key > rnode->left->key)
    {
        rnode->left = leftRotate(rnode->left);
        return rightRotate(rnode);
    }

    // RL Case
    if (balance < -1 && key < rnode->right->key)
    {
        rnode->right = rightRotate(rnode->right);
        return leftRotate(rnode);
    }

    return rnode; // no change in root
}
void Dictionary::preorder()
{
    preorderRec(root);
}
void Dictionary::postorder()
{
    postorderRec(root);
}
void Dictionary::inorder()
{
    inorderRec(root);
}
void Dictionary::preorderRec(node *n)
{
    if (n)
    {
        n->print();
        preorderRec(n->left);
        preorderRec(n->right);
    }
}

void Dictionary::inorderRec(node *n)
{
    if (n)
    {
        inorderRec(n->left);
        n->print();
        inorderRec(n->right);
    }
}

void Dictionary::postorderRec(node *n)
{
    if (n)
    {
        postorderRec(n->left);
        postorderRec(n->right);
        n->print();
    }
}
void Dictionary::insertInit(int key, string meaning)
{
    root = insert(root, key, meaning);
}

void Dictionary::postorder_dec()
{
    postorder_dec(root);
}

void Dictionary::postorder_dec(node *n)
{
    if (n)
    {
        postorder_dec(n->right);
        n->print();
        postorder_dec(n->left);
    }
}

int main()
{
    Dictionary d;
    d.insertInit(1, "Vaibhav");
    d.insertInit(3, "Navnath");
    d.insertInit(2, "Kumbhar");
    d.insertInit(5, "Ganesha");
    d.insertInit(4, "Five");

    // d.insertInit(10,"10");
    // d.insertInit(20,"20");
    // d.insertInit(30,"30");
    // d.insertInit(40,"40");
    // d.insertInit(50,"50");
    // d.insertInit(25,"25");
    cout << "\nASCENDING ORDER: ";
    d.inorder();

    cout << "\nDECENDING ORDER: ";
    d.postorder_dec();

    cout << "\nPreorder: ";
    d.preorder();

    cout << "\nPostorder: ";
    d.postorder();

    return 0;
}