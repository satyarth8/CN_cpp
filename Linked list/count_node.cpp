#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *link;
};
void count_of_node(struct node* head) {
    int count = 0;
    if (head == nullptr)
        cout << "Linked list is empty";
    struct node* ptr = nullptr;
    ptr = head;
    while (ptr != nullptr) {
        count++;
        ptr = ptr->link;
    }
    cout << count;
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
    delete current;
    delete head;
    return 0;
}