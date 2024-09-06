#include<iostream>
using namespace std;

// Define the structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor for new nodes
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to calculate the height of the binary tree
int height(Node* root) {
    if (root == nullptr)  // Base case: if the node is null, height is 0
        return 0;

    // Recursively calculate the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // The height of the current node is 1 plus the maximum of the left and right subtree heights
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = new Node(1);   // Root node with value 1
    root->left = new Node(2);   // Left child of root
    root->right = new Node(3);  // Right child of root
    root->left->left = new Node(4);   // Left child of the left node
    root->left->right = new Node(5);  // Right child of the left node
    
    cout << "Height of the tree: " << height(root) << endl;

    return 0;
}
