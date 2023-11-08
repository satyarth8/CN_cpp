#include <iostream>
// print fn // add at start fn // add at last // ok so i have and array i to put all the value in a linked list
using namespace std;

struct node 
{
    int data;
    struct node* link;
};

void add_at_end(struct node* head, int value)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = value;
    ptr->link = nullptr;
    
    struct node* current = head;
    while (current->link != nullptr) {
        current = current->link;
    }
    
    current->link = ptr;
}

void print_sll(struct node* head)
{
    struct node* current = head->link; // Skip the dummy head node
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->link;
    }
    cout << endl;
}
struct node* add_at_start(struct node *head_ptr,int value)
{
    struct node* temp= (struct node*) malloc(sizeof(struct node ));
    temp->data=value;
    temp->link=head->link;
    head_ptr=temp;
    return head_ptr;
}

int main() {
    int arr[5] = {1, 34, 5, 45, 6};
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head->data = 0; // Initialize the dummy head node with some value
    head->link = nullptr;

    for (int i = 0; i < 5; i++) {
        add_at_end(head, arr[i]);
    }
    head = add_at_start(head,23);
    print_sll(head);

    return 0;
}
