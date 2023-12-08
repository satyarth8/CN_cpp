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
int main() {
    node* root= createnode(10);
    root->left=createnode(20);
    root->right=createnode(30);

    cout<<root->data<<" "<<root->left->data<<" "<<root->right->data;
    cout<<" Total no. of nodes "<<count_Nodes(root);
    return 0;
}