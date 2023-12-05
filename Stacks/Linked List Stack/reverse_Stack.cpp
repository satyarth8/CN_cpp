#include <iostream>

using namespace std;

struct node
{
    int data;
    node* link;
};

void push(int data, node** top)
{
    node* temp=new node;
    if(temp==nullptr)
    {
        cout<<"Stack overflow";
        exit(1);
    }
    temp->data=data;
    temp->link=nullptr;
    
    temp->link=*top;
    *top=temp;
}
int isEmpty(node** top)
{
    if (*top==nullptr)
        return 1;
    else
        return 0;
}
int pop(node** top)
{
    node* temp=new node;
    int val;
    if(isEmpty(top))
    {
        printf("stack underflow");
        exit(1);
    }
    temp=*top;
    val=temp->data;
    *top=(*top)->link;
    free(temp);
    temp=nullptr;
    return val;
}

void reverse_stack(node** top)
{
    node*top1=nullptr;
    node*top2=nullptr;
    while(*top!=nullptr)
    {
        push(pop(top),&top1);
    }
    while(top1!=nullptr)
    {
        push(pop(&top1),&top2);
    }
    while(top2!=nullptr)
    {
        push(pop(&top2),top);
    }
}

void print(node** top)
{
    node* temp;
    temp=*top;
    if(isEmpty(top))
    {
        cout<<"Stack underflow";
        exit(1);
    }
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
}

int main() 
{ 
    node* top=nullptr;
    push(99,&top);
    push(88,&top);
    push(77,&top);
    print(&top);
    cout<<"\n";
    reverse_stack(&top);
    print(&top);
}