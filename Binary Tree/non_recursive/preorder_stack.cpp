#include <iostream>

using namespace std;
#define MAX 20

struct node{
    node* left;
    int data;
    node* right;
};

struct node* stack[MAX];
int top =-1;

void push( node* ptr)
{

    if(top==MAX-1)
    {
        cout<<"Stack overflow";
        exit(1);
    }
    top++;
    stack[top]=ptr;

}

node* pop()
{
    if (top == -1)
    {
        cout << "Stack underflow";
        exit(1);
    }
    node* ptr = stack[top];
    top--;
    return ptr;
}


node* createnode(int data)
{
    node* temp=new node;
    temp->data=data;
    temp->right=nullptr;
    temp->left=nullptr;
    return temp;
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void preorder(node* root)
{

    if(root==nullptr)
    {  
        cout<<"Empty tree";
        exit(1);
    }

    node* ptr=root;
    push(ptr);
    while(!isEmpty())
    {
        ptr=pop();
        cout<<ptr->data<<" ";
        if(ptr->right!=nullptr)
        {
            push(ptr->right);
        }
        if(ptr->left !=nullptr)
        {
            push(ptr->left);
        }
    }
}
int main() 
{
    node* root=nullptr;
    root=createnode(1);
    root->left=createnode(2);
    root->right=createnode(3);
    root->left->left=createnode(4);
    root->left->right=createnode(5);
    root->left->right->left=createnode(6);
    root->left->right->right=createnode(7);
    preorder(root);
    return 0;
}

