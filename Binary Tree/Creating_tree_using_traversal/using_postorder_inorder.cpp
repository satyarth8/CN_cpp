#include <iostream>

using namespace std;
struct node{
    node* left;
    node* right;
    char data;
};
struct node* createNode(char data)
{
    node* ptr=new node;
    ptr->left=nullptr;
    ptr->data=data;
    ptr->right=nullptr;
    return ptr;
}

int searchIn(char inArr[],char data,int inStart, int inEnd)
{
    int i;
    for(i=inStart;i<=inEnd;i++)
    {
        if(inArr[i]==data)
        {
            return i;
        }
    }
}
struct node* constructBT(char inArr[],char postArr[],int inStart, int inEnd)
{
    static int postIndex=inEnd;
    if (inStart>inEnd)
        return nullptr;
    struct node* temp= createNode( postArr[postIndex]);
    postIndex--;
    if(inStart==inEnd)
        return temp;
    
    int inIndex=searchIn(inArr,temp->data,inStart,inEnd);
    temp->right=constructBT(inArr,postArr,inIndex+1,inEnd);
    temp->left=constructBT(inArr,postArr,inStart,inIndex-1);
    return temp;
}
void printpre(struct node* root)
{
    if(root==nullptr)
    {
        return;
    }

    printpre(root->left);
    printpre(root->right);
    cout<<root->data;
}

int main()
{
    char postArr[]={'D','E','B','F','C','A'};
    char inArr[]={'D','B','E','A','F','C'};
    int length =sizeof(inArr)/sizeof(inArr[0]);
    struct node* root=constructBT(inArr,postArr,0,length-1);
    printpre(root);
    return 0;
}

