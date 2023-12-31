#include <iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* createNode(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

node* nonRecSearch(node* root, int skey) {
    while (root != nullptr) {
        if (skey < root->data) {
            root = root->left;
        } else if (skey > root->data) {
            root = root->right;
        } else {
            return root;
        }
    }
    return nullptr;
}
// NON RECURSIVE APPROACH
int main() {
    // Create a balanced binary tree
    node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(9);

    // Search for a node with key 7
    node* result = nonRecSearch(root, 9);
    if (result != nullptr) {
        cout << "Found node with key " << result->data << endl;
    } else {
        cout << "Node not found" << endl;
    }

    return 0;
}