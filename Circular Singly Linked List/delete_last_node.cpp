#include <iostream>
using namespace std;
struct node{
    int data;
     node* next;
};

node* addToEmpty(node* tail,int data)
{
    node* temp= new node;
    temp->data=data;
    temp->next=temp;
    return temp;
}
node* add_at_beg(node* tail, int value)
{
    node* temp=new node;
    temp->next=tail->next;
    temp->data=value;
    tail->next=temp;
    return tail;
}
node* add_at_end(node* tail, int value)
{
    node* temp= new node;
    temp->data=value;
    temp->next=tail->next;
    tail->next=temp;
    tail=temp;
    return tail;// temp is the new end so we can return temp too
}
node* delete_last_node(node* tail)
{
    node* temp=tail->next;
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    return temp;
}
void print(node* tail)
{
    node* ptr = tail->next;
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != tail->next);

    cout << endl;

}
int main() {
    int n, val;
    node* tail = new node;

    cout << "Enter the number of elements you want: ";
    cin >> n;

    cout << "Enter the value to be added: ";
    cin >> val;
    tail = addToEmpty(tail, val);
    for (int i = 1; i <n; i++) 
    {
        cout << "Enter the value to be added : ";
        cin >> val;
        tail = add_at_end(tail, val);
    }
    cout << "Circular Linked List after deleting the first node:" << endl;
    tail=delete_last_node(tail);
    print(tail);

    return 0;
}