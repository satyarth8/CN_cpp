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
// Non recursive implementation
struct node* NonRecMin(struct node* root)
{
    if(root!=nullptr)
    {
        while(root->left!=nullptr)
            root=root->left;
    }
    return root;
}

// recursive implementation
struct node* RecMin(struct node* root)
{
    if(root==nullptr)
        return nullptr;
    else if(root->left==nullptr)
        return root;
    else
        return RecMin(root->left);
}

int main() {
    // Create a balanced binary tree
    node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(9);

    cout<<"The min element in the BSt is "<<RecMin(root)->data;
    return 0;
}