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

int searchIn(char inArr[],char data, int inEnd)
{
    int i;
    for(i=0;i<=inEnd;i++)
    {
        if(inArr[i]==data)
        {
            return i;
        }
    }
}
struct node* constructBT(char inArr[],char preArr[],int inStart, int inEnd)
{
    static int preIndex=0;
    if (inStart>inEnd)
        return nullptr;
    node* temp=createNode(preArr[preIndex]);
    preIndex++; 
    if(inStart == inEnd)
        return temp;
    int inIndex=searchIn(inArr,temp->data,inEnd);
    temp->left=constructBT(inArr,preArr,inStart, inIndex-1);
    temp->right=constructBT(inArr,preArr,inIndex+1 ,inEnd);
    return temp;
}


void printpre(struct node* root)
{
    if(root==nullptr)
    {
        return;
    }
    cout<<root->data;
    printpre(root->left);
    printpre(root->right);
}


int main() {
    // Your code here
    char preArr[]={'A','B','D','E','C'};
    char inArr[]={'D','B','E','A','C'};
    int length=sizeof(inArr)/sizeof(inArr[0]);
    node* root=constructBT(inArr,preArr,0,length-1);
    printpre(root);
    return 0;
}
