#include <iostream>

using namespace std;

struct node 
{
    node* prev=nullptr;
    node* next=nullptr;
    int data;
};
node* create_dll(int val)
{
    node* temp= new node;
    temp->data=val;
    temp->prev=temp;
    temp->next=temp;
    return temp;
}
void print(node* tail)
{
    node* temp=tail->next;

    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail->next);

}
node* add_at_end(   node* tail,int val )
{
    node* temp=new node;
    temp->data=val;
    //prev connection;
    temp->next=tail->next;
    temp->prev=tail;
    tail->next=temp;
    return temp;

}
int main() 
{
    node* tail=nullptr;
    tail=create_dll(45);
    tail=add_at_end(tail,334);
    tail=add_at_end(tail,223);
    print(tail);
    return 0;
}