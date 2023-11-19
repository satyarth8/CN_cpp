#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node* link;
};
void print(struct node *head)
{
    struct node  *ptr=head;
    while(ptr!=nullptr)
    {
        cout<<ptr->data<< endl;
        ptr=ptr->link;

    }
}
struct node* add_at_start(struct node *head, int value)
{
    struct node *temp =(struct node*) malloc(sizeof(struct node));
    temp->data=value;
    temp->link=head;
    return temp;
}
struct node* rev_sll(struct node *head)
{
    struct node* prev=nullptr;
    struct node* next=nullptr;
    while(head!=nullptr)
    {
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
}
int main() {
    // Your code here
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->data=2;
    head->link=nullptr;
    head=add_at_start(head,4);
    head=add_at_start(head,8);
    head=add_at_start(head,16);
    head=add_at_start(head,32);
    head=add_at_start(head,64);
    cout<<"before reversing"<<endl;
    print(head);
    cout<<"after reversing"<<endl;
    head=rev_sll(head);
    print(head);
    return 0;
}