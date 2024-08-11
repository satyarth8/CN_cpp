#include <iostream>
#include <stdexcept>
using namespace std;
// Node structure for the BST
struct Node {
    int value; // Value of the node
    Node* left; // Pointer to the left child
    Node* right; // Pointer to the right child

    // Constructor to initialize a node with a given value
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        // If the root is null, create a new node with the given value
        return new Node(val);
    }

    if (val < root->value) {
        // Insert in the left subtree if the value is smaller
        root->left = insert(root->left, val);
    } else if (val > root->value) {
        // Insert in the right subtree if the value is larger
        root->right = insert(root->right, val);
    } else {
        // If the value is equal to the root's value, throw an exception for a duplicate
        throw runtime_error("Duplicate value");
    }

    return root; // Return the updated root
}

// In-order traversal to print BST elements
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->value << " ";
        inOrderTraversal(root->right);
    }
}

// Main function to demonstrate insertion in a BST
int main() {
    Node* root = nullptr; // Initially, the BST is empty

    try {
        // Insert values into the BST
        root = insert(root, 10);
        root = insert(root, 5);
        root = insert(root, 15);
        root = insert(root, 7);

        cout << "BST elements (in-order): ";
        inOrderTraversal(root); // Output the BST in-order
        cout << endl;

        // This will raise an exception due to a duplicate value
        root = insert(root, 10);
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
