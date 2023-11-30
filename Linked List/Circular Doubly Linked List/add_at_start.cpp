#include <iostream>

using namespace std;
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};
node* create_dll(int val)
{
    node* temp= new node;
    temp->data=val;
    temp->prev=temp;
    temp->next=temp;
    return temp;
}
node* add_at_beg(node* tail, int val)
{
    node* temp= new node;
    temp->data=val;
    temp->prev=tail;
    temp->next=tail->next;
    tail->next->prev=temp;
    tail->next=temp;
    return tail;
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
int main() {
    node* tail=nullptr;
    tail=create_dll(45);
    tail=add_at_beg(tail,334);
    tail=add_at_beg(tail,399);
    print(tail);

    return 0;
}