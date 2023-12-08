#include <iostream>

using namespace std;

struct node{
    int data;
    node* right;
    node* left;
};
struct node* createTree()
{
    int input,data;
    cout<<"Do you want to add a node? ( 0 for no and 1 for yes)";
    cin>>input;
    cout<<endl;
    if(!input)
        return nullptr;
    else
    {
        node* temp= new node;
        cout<<"Enter the data:";
        cin>>data;
        temp->data=data;
        cout<<"Left Child of "<<temp->data<<endl;
        temp->left=createTree();
        cout<<"Right Child of "<<temp->data<<endl;
        temp->right=createTree();
        return temp;
    }
}
int main() {
    node* root=createTree();
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    return 0;
}