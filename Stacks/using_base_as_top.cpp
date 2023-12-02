#include <iostream>
#define MAX 5
using namespace std;

int stack_arr[MAX];
int first=-1;

void push(int data)
{
    first++;
    for(int i=first;i>0;i--)
    {
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data;
}
int pop()
{
    int value;
    value=stack_arr[0];
    for(int i=0;i<first;i++)
    {
        stack_arr[i]=stack_arr[i+1];
    }
    first--;
    return value;
}
void print()
{
    if(first==-1)
    {
        cout<<"empty stack";
        exit(1);
    }
    for(int i=0;i<=first;i++)
    {
        cout<<stack_arr[i]<<" ";
    }


}
int isFull()
{
    if(first==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if(first==-1)
        return 1;
    else
        return 0;
}

int peek()
{ // gives the topmost element;
    if(isEmpty())
    {
        cout<<"Stack Underflow";
        exit(1);
    }
    cout<<"\npeeked value : ";
    return stack_arr[0];
}
int main() 
{
    int data;
    push(1);
    push(2);
    push(3);
    data=pop();

    print();

    cout<<peek();
    return 0;
}