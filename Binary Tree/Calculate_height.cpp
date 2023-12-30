#include <iostream>

using namespace std;
struct node{
    struct node* left;
    char data;
    struct node* right;
};
int heightBT(struct node* root)
{   
    if(root==nullptr)
        return 0;
    if(root->left==nullptr && root->right==nullptr)
        return 0;
    int left=heightBT(root->left);
    int right=heightBT(root->right);
    if(left>right)
        return left+1;
    else   
        return right+1;
    
}
struct node* createNode(char data)
{
    struct node* ptr=new node;
    ptr->left=nullptr;
    ptr->data=data;
    ptr->right=nullptr;
    return ptr;
}
int main() {
    struct node* root=nullptr;
    root=createNode('a');
    root->left=createNode('b');
    root->right=createNode('e');
    root->left->left=createNode('c');
    root->left->right=createNode('d');
    root->right->left=createNode('f');
    root->left->left->left=createNode('g');
    int height=heightBT(root);
    cout<<height;
    return 0;
}