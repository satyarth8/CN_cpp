#include <iostream>

using namespace std;
struct node{
    struct node* left;
    int data;
    struct node* right;

};
struct node* createNode(int data)
{
    node* ptr=new node;
    ptr->left=nullptr;
    ptr->data=data;
    ptr->right=nullptr;
    return ptr;
}
int heightBT( struct node* root)
{
    if( root==nullptr)
        return -1;
    if(root->left ==nullptr && root->right==nullptr)
        return 0;
    int left=heightBT(root->left);
    int right=heightBT(root->right);
    if(left>right)
        return left+1;
    else
        return right+1;
}
int isBalanced(struct node* root)
{
    int l=0, r=0, diff=0;
    int lh=0,rh=0;

    if(root ==nullptr)
        return 1;

    l=isBalanced(root->left);
    r=isBalanced(root->right);

    if(l && r)
    {
        lh=heightBT(root->left);
        rh=heightBT(root->right);
        diff=abs((lh+1)-(rh+1));
        if(diff <=1)
            return 1;
    }
    return 0;
}


int main() {
    struct node* root=nullptr;
    root=createNode(50);
    root->left=createNode(40);
    root->right=createNode(60);
    root->right->left=createNode(55);
    // root->right->left->right=createNode(57);

    if(isBalanced(root))
        cout<<"Tree is height balanced";
    else
        cout<<"Tree is not height balanced";
    return 0;
}