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

    struct node *current1 =(struct node*)malloc(sizeof(struct node));
    current1->data=12;
    current1->link=NULL;
    head->link=current1;

    struct node *current2 =(struct node*)malloc(sizeof(struct node));
    current2->data=24;
    current2->link=NULL;
    current1->link=current2;
    cout<<current1->data<<endl;
    cout<<current2->data<<endl;
    cout<<head->link->link->data<<endl;
    free(current1);
    free(current2);
    free(head);
    return 0;
}