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
void del_pos(struct node **head,int position)
{
    struct node* current =*head;
    struct node* previous =*head;
    if(*head=nullptr)
        cout<<" the linked list is empty";
    else if(position==1)
    {
        *head=current->link;
        free(current);
        current =nullptr;
    }
    else 
    {
        while(position!=1)
        {
            previous =current;
            current =current ->link;
            position--;
        }
        previous ->link = current ->link;
        free(current);
        current=nullptr;
    }
    
}
int main() {
    // Your code here
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->data=23;
    head->link=nullptr;
    head=add_at_start(head,233);
    head=add_at_start(head,2666);
    head=add_at_start(head,266);
    head=add_at_start(head,26);
    head=add_at_start(head,7);
    del_pos(&head,4);
    print(head);
    return 0;
}