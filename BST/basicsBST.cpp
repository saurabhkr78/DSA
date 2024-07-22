/*
A Binary Search Tree (BST) is a binary tree in which each node has at most two children, and for each node:

The left subtree contains only nodes with keys less than the node's key.
The right subtree contains only nodes with keys greater than the node's key.
#every node to the left of a node should be smaller and every node to the right should be greater and this applies for all nodes.
#LST<root->val<RST so no duplicate elements in BST
#if LST<=root->val<RST then chances of duplicate elements
#not efficeint in unbalanced tree




*/
#include <iostream>
using namespace std;

// Define a node structure
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Insert a new node into the BST
Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Search for a value in the BST
bool search(Node *root, int value)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == value)
    {
        return true;
    }
    else if (value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

// In-order traversal of the BST
void inOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main()
{
    Node *root = nullptr;

    // Insert elements into the BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    // Print in-order traversal of the BST
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Search for a value in the BST
    int searchValue = 4;
    if (search(root, searchValue))
    {
        cout << searchValue << " found in the BST." << endl;
    }
    else
    {
        cout << searchValue << " not found in the BST." << endl;
    }

    return 0;
}
