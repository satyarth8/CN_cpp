#include <iostream>

using namespace std;
struct node
{
    int data;// structure prototype
    struct node *link; 
};
void add_at_end(struct node* head, int value) {

    if (head == nullptr) // if no data present or ll is empty
        cout << "Linked list is empty";
    struct node* ptr = nullptr;
    // made a temp struct and gave the data the value and link as null as adding at the end
    struct node* temp=(struct node*) malloc(sizeof(struct node ));
    temp->data=value; 
    temp->link=nullptr;
    ptr = head;
    // ptr is a structure pointer 
    while (ptr->link != nullptr) // ptr pointign to each of the link 
    {
        ptr=ptr->link;
        // when at the last link get out of loop
    }
    // to the last node give the link the addr of the temp which had the value data
    ptr->link=temp;
}
void count_of_node(struct node* head) 
{ // just casually printing all the data
    if (head == nullptr)
        cout << "Linked list is empty";
    struct node* ptr = nullptr;
    ptr = head;
    while (ptr != nullptr) {
        cout<<ptr->data<<endl;
        ptr = ptr->link;
    }
}
int main() {
    // Your code here
    struct node *head =(struct node* ) malloc(sizeof(struct node));
    head->data=11;
    head->link=NULL;

    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->data=12;
    current->link=NULL;
    head->link=current;

    current =(struct node*)malloc(sizeof(struct node));
    current->data=24;
    current->link=NULL;
    head->link->link=current;
    count_of_node(head);
    add_at_end(head,23);
    count_of_node(head);
    delete current;
    delete head;
    return 0;
}