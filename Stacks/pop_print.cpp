#include <iostream>
#define MAX 4

int stack_arr[MAX];
int top=-1;

using namespace std;
void push(int data)
{
    if(top-1==MAX)
    {
        cout<<"Stack overflow";
        return;
    }
    top++;
    stack_arr[top]=data;
}

int pop()
{
    if(top==-1)
    {
        cout<<"stack underflow";
        exit(1);
    }
    int value=stack_arr[top];
    cout<<stack_arr[top];
    top--;
    return value;
}

void print()
{
    if(top==-1)
    {
        cout<<"stack underflow";
        return;
    }
    for(int i=top;i>=0;i--)
    {
        cout<<stack_arr[i]<<" ";
    }
    cout<<endl;

}
int main() {
    int data;
    push(1);
    push(2);
    push(3);
    push(4);
    cout<<"the stack before poping : ";
    print();
    data=pop();
    cout<<"\npoping once gave this value : "<<data<<endl;
    cout<<"the stack after poping : ";
    print();

    return 0;
}
