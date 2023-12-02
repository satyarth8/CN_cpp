#include <iostream>

using namespace std;

struct node
{
    int data;
    node* link;
} *top=nullptr;

void push(int data)
{
    node* temp=new node;
    if(temp==nullptr)
    {
        cout<<"Stack overflow";
        exit(1);
    }
    temp->data=data;
    temp->link=top;
    top=temp;
}
int isEmpty()
{
    if (top==nullptr)
        return 1;
    else
        return 0;
}
int pop()
{
    int value;
    node* temp=new node;
    temp=top->link;
    value=top->data;
    top=temp;
    return value;
}
void print()
{
    node* ptr=top;
    if(isEmpty())
    {
        cout<<"Stack underflow";
        exit(1);
    }
    while(ptr!=nullptr)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
}
int peek()
{
    if(isEmpty())
    {
        cout<<"Stack underflow";
        exit(1);
    }
    return top->data;
}
int main() {
    push(10);
    push(11);
    cout<<"before pop :";
    print(); 
    cout<<"\npoped value :"<<pop();
    push(99);
    cout<<"\ncurrent stack :";
    print();
    // Your code here
    return 0;
}