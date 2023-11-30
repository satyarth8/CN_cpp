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
struct node* add_at_pos(struct node *head,int pos,int value)
{
    int count=0;
    struct node* ptr=head;
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    temp->data=value;
    temp->link=nullptr;
    while(ptr!=nullptr)
    {
        count++;
        if(count==pos)
        {
            temp->link=head->link;
            head->link=temp;
        }
        ptr=ptr->link;
    }
    return head;
}
struct node* del_first( struct node* head)
{
    if(head==nullptr)
    {
        cout<<"the ll is empty";
    }
    else
    {
        struct node* temp=head;
        head=head->link;
        free(temp);
        temp=nullptr;
    }
    return head;
}
int main() {
    // Your code here
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->data=23;
    head->link=nullptr;
    head=add_at_start(head,233);
    head=add_at_start(head,10);
    head=add_at_start(head,48);
    head=add_at_pos(head,2,99);
    head=del_first(head);
    print(head);
    return 0;
}