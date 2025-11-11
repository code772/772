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

// Search node (fixed recursive version)
void searchNode(node* temp, int value) 
{
    if (temp == NULL) 
    {
        cout << "Not found" << endl;
        return;
    }

    if (temp->data == value) 
    {
        cout << "Found" << endl;
        return;
    }

    if (value < temp->data)
        searchNode(temp->left, value);
    else
        searchNode(temp->right, value);
}

int main() 
{
    int val;
    char ch;

    // Insert nodes using do-while
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

    // Search nodes using do-while
    do 
    {
        cout << "Enter value to search: ";
        cin >> val;
        searchNode(root, val);

        cout << "Do you want to search more values (y/n): ";
        cin >> ch;
    } 
    while (ch == 'y' || ch == 'Y');

    return 0;
}