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
node* del_first_node(node* tail)
{
    node* temp=tail->next;
    tail->next=temp->next;
    temp->next->prev=tail;
    free(temp);
    return tail;
}
int main() 
{
    node* tail=nullptr;
    tail=create_dll(45);
    tail=add_at_end(tail,334);
    tail=add_at_end(tail,223);
    tail=del_first_node(tail);
    print(tail);
    return 0;
}