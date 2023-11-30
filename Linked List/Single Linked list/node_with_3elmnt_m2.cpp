#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *link;
};
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
    cout<<head->data<<endl;
    cout<<head->link->data<<endl;
    cout<<head->link->link->data<<endl;
    free(current);
    free(head);
    return 0;
}