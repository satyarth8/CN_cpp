#include <iostream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};
node* createnode(int value)
{
    node* temp=new node;
    temp->data=value;
    temp->left=nullptr;
    temp->right=nullptr;
    return temp;
}

int count_Nodes(struct node* root)
{
    if(root==nullptr)
        return 0;
    else if(root->left ==nullptr && root->right ==nullptr)
        return 1;
    else{
        int left=count_Nodes(root->left);
        int right=count_Nodes(root->right);
        return (1+left+right);
    }
}
int isCompleteBinaryTree(node* root,int i,int count)
{
    if(root==nullptr)
    {
        return 1;
    }
    if(i>=count)
    {
        return 0;
    }
    int left=isCompleteBinaryTree(root->left,2*i+1,count);
    int right=isCompleteBinaryTree(root->right,2*i+2,count);
    return (left && right);
}
int main() {
    node* root= createnode(10);
    root->left=createnode(20);
    root->right=createnode(30);
   // root->right->left=createnode(32);
    //root->left->right=createnode(232);
    cout<<root->data<<" "<<root->left->data<<" "<<root->right->data;
    int val =count_Nodes(root);
    cout<<" Total no. of nodes "<<val<<endl;
    if(isCompleteBinaryTree(root,0,val))
        cout<<"It is a Complete Binary Tree";
    else
        cout<<"Not a Complete Binary Tree";
    return 0;
}