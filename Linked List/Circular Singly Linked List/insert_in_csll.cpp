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
node* add_at_pos(node* tail, int value , int pos)
{
    node* temp= new node;
    node* ptr=tail->next;
    temp->data=value;
    temp->next=nullptr;
    while(pos>1)
    {
        ptr=ptr->next;
        pos--;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    if(ptr==tail)
    {
        tail=tail->next;
    }
    return tail;
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

    cout << "Enter the value to be put at last: ";
    cin >> val;
    tail = addToEmpty(tail, val);

    for (int i = 1; i < n; i++) {
        cout << "Enter the value to be added at the start: ";
        cin >> val;
        tail = add_at_beg(tail, val);
    }
    int val2,pos;
    cout<<"enter the value of extra element you want to be added:";
    cin>>val2;
    cout<<"enter the position you want to add it to";
    cin>>pos;
    tail=add_at_pos(tail,val2,pos);
    cout << "Circular Linked List:" << endl;
    print(tail);

    return 0;
}