#include <iostream>

using namespace std;
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
void  insert_to_empty_dll(struct node* head, int value)
{
    head->prev=nullptr;
    head->next=nullptr;
    head->data=value;
}
node* add_at_start(struct node* head, int value)
{
    node* temp=new node;
    temp->prev=nullptr;
    temp->data=value;
    temp->next=head;
    head->prev=temp;
    return temp;
}
node* add_at_end(struct node* head, int value)
{
    node* temp=new node;
    temp->data=value;
    node* ctr=head;
    while(ctr->next!=nullptr){
        ctr=ctr->next;
    }
    ctr->next=temp;
    temp->prev=ctr;
    temp->next=nullptr;
    return head;
}
int main() {
    struct node* head= (struct node*) malloc(sizeof(struct node));
    insert_to_empty_dll(head,23);

    head=add_at_start(head,124);
    head=add_at_start(head,2412);
    head=add_at_end(head,999);
    struct node* ptr=head;
    while(ptr!= nullptr)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
    return 0;
}