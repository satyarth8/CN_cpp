#include <iostream>

using namespace std;
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;

int stack[MAX];
int top=-1;

int q_isFull()
{
    if(rear==MAX-1)
        return 1;
    else
        return 0;
}
int q_isEmpty()
{
    if(front==-1||front==rear+1)
        return 1;
    else    
        return 0;
}
void push(int data)
{
    if(top==MAX-1)
    {
        cout<<"Stack is full";
        exit(1);
    }
    top++;
    stack[top]=data;
}

int pop()
{
    if(top==-1)
    {
        cout<<"Stack underflow";
        exit(1);
    }
    
    int val=stack[top];
    top--;
    return val;
}
void enqueue(int data)
{
    if(q_isFull())
    {
        cout<<"Queue overflow";
        exit(1);
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=data;
}

int dequeue()
{
    if(q_isEmpty())
    {
        cout<<"Queue underflow";
        exit(1);
    }
    int val=queue[front];
    front++;
    return val;
}
void reverse()
{
    while(top!=-1)
    {
        enqueue(pop());
    }
    while(!q_isEmpty())
    {
        push(dequeue());
    }    
}
void print()
{
    for(int i=0;i<=top;i++)
    {
        cout<<" "<<stack[i];
    }
}
int main() 
{
    push(10);
    push(20);
    push(30);
    push(40);
    reverse();
    print();
    return 0;
}