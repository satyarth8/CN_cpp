#include <iostream>
#define MAX 100


using namespace std;
int stack_Arr[100];
int top=-1;

void push(int data)
{
    if(top>=MAX)
    {
        cout<<"stack overflow";
        exit(1);
    }
    top++;
    stack_Arr[top]=data;
}
int pop()
{
    if(top==-1)
    {
        cout<<"stack underflow";
        return -1;
    }
    int value=stack_Arr[top];
    top--;
    return value;

}
void tobinary(int n)
{
    while(n!=0)
    {
        push(n%2);
        n=n/2;
    }
    
    while(top!=-1){
        cout<<pop()<<" ";
    }
}
int main() {
    int n;
    cout<<"Enter a number to get its Binary Representation : ";
    cin>>n;
    cout<<"\nThe Binary Representation is ";
    tobinary(n);
    return 0;
}