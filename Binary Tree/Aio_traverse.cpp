#include <iostream>

using namespace std;

struct node
{
    char data;
    node* left;
    node* right;
};
node* createnode(char value)
{
    node* temp=new node;
    temp->data=value;
    temp->left=nullptr;
    temp->right=nullptr;
    return temp;
}
void inorder(node* root)
{
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

void preorder(node* root)
{
    if(root==nullptr)
        return;
    cout<<" "<<root->data;
    preorder(root->left);
    preorder(root->right);
}


int main() {
    node* root= createnode('A');
    root->left=createnode('B');
    root->right=createnode('C');
    root->left->left=createnode('D');
    root->left->right=createnode('E');
    root->right->right=createnode('F');
    inorder(root);
}