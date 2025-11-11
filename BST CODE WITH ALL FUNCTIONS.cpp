#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* root = NULL;

// Insert node in BST
void insertNode(int value) 
{
    node* nn = new node;
    nn->data = value;
    nn->left = NULL;
    nn->right = NULL;

    if (root == NULL) 
    {
        root = nn;
        return;
    }

    node* temp = root;
    while (true) 
    {
        if (value < temp->data) 
        {
            if (temp->left == NULL) 
            {
                temp->left = nn;
                break;
            }
            temp = temp->left;
        } 
        else 
        {
            if (temp->right == NULL) 
            {
                temp->right = nn;
                break;
            }
            temp = temp->right;
        }
    }
}

// Inorder traversal
void inorder(node* temp) 
{
    if (temp != NULL) 
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

// Find minimum value
void findMin(node* temp) 
{
    if (temp == NULL) 
    {
        cout << "Tree is empty" << endl;
        return;
    }
    while (temp->left != NULL)
        temp = temp->left;
    cout << "Minimum value: " << temp->data << endl;
}

// Search node (iterative, works correctly)
void searchNode(node* temp, int value)
{
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Found" << endl;
            return;
        }
        if (value < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    cout << "Not found" << endl;
}

// Find height (longest path from root)
int height(node* temp)
{
    if (temp == NULL)
        return 0;
    int l = height(temp->left);
    int r = height(temp->right);
    return (l > r ? l : r) + 1;
}

// Mirror tree
void mirror(node* temp)
{
    if (temp != NULL)
    {
        node* t = temp->left;
        temp->left = temp->right;
        temp->right = t;

        mirror(temp->left);
        mirror(temp->right);
    }
}

int main() 
{
    int val;
    char ch;

    // Insert nodes interactively
    do 
    {
        cout << "Enter value to insert: ";
        cin >> val;
        insertNode(val);

        cout << "Do you want to insert more nodes (y/n): ";
        cin >> ch;
    } 
    while (ch == 'y' || ch == 'Y');

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    findMin(root);

    cout << "Height of tree: " << height(root) << endl;

    // Search nodes interactively BEFORE mirroring
    do 
    {
        cout << "Enter value to search: ";
        cin >> val;

        searchNode(root, val); // accurate now

        cout << "Do you want to search more values (y/n): ";
        cin >> ch;
    } 
    while (ch == 'y' || ch == 'Y');

    // Mirror tree
    mirror(root);
    cout << "Inorder after mirroring: ";
    inorder(root);
    cout << endl;

    return 0;
}