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
struct node* insert_nonRec(struct node* root, int ikey)
{
    struct node* ptr;
    ptr=root;
    node* parent=nullptr;
    while(ptr!=nullptr)
    {
        parent=ptr;
        if(ikey<ptr->data)
            ptr=ptr->left;
        else if (ikey > ptr->data)
            ptr=ptr->right;
        else
        {
            cout<<"Duplicate key"<<endl;
            return root;
        }
    }
    node* temp=new node;
    temp=createNode(ikey);
    if(parent==nullptr)
        root=temp;
    else if (ikey<parent->data)
        parent->left=temp;
    else   
        parent->right =temp;
    return root;
}

struct node* insert_Rec(struct node* root, int ikey)
{
    if(root== nullptr)
        root=createNode(ikey);
    else if(ikey<root->data)
        root->left = insert_Rec(root->left,ikey);
    else if(ikey>root->data)
        root->right = insert_Rec(root->right,ikey);
    else    
        cout<<"Duplicate Key";
    return root;
}

void printBST(struct node* root)
{
    if(root==nullptr)
        return;
    printBST(root->left);
    cout<<root->data<<" ";
    printBST(root->right);
}

int main()
{
    struct node* root=nullptr;
    int arr[9]={67,34,80,10,55,45,45,60,90};
    for( int i=0;i<9;i++)
    {
        root=insert_Rec(root,arr[i]);
    }
    printBST(root);
    return 0;
}