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
int count_nodes(node* tail)
{
    int counter =1;
    node* temp=tail;
    while(temp!=tail)
    {
        counter++;
        temp=temp->next;
    }
    return counter;
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
    cout << "Circular Linked List:" << endl;
    
    print(tail);
    cout<<"The counted no. of nodes is : "<<count_nodes(tail);

    return 0;
}