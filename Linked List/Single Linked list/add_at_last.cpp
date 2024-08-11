#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *link; 
};
void append(struct node* head, int value) {

    if (head == nullptr)
        cout << "Linked list is empty";
    struct node* ptr = nullptr;
  
    struct node* temp=(struct node*) malloc(sizeof(struct node ));
    temp->data=value; 
    temp->link=nullptr;
    ptr = head;

    while (ptr->link != nullptr)  
    {
        ptr=ptr->link;
       
    }
    ptr->link=temp;
}
void print(struct node* head) 
{ 
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
    
    printf("before append :\n");
    print(head);
    printf("after append :\n");
    append(head,23);
    print(head);
    delete current;
    delete head;
    return 0;
}