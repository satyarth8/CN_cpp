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
int main() {
    // Your code here
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->data=23;
    head->link=nullptr;
    head=add_at_start(head,233);
    print(head);
    return 0;
}