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
void prime_fact(int num)
{
    int fact=2;
    while(num!=1)
    {
        while(num%fact==0 )
        {
            push(fact);
            num=num/fact;
        }
        fact++;
    }

    while(top!=-1){
        cout<<pop()<<" ";
    }
}
int main() {
    int n;
    cout<<"Enter a number to get its Prime Factors : ";
    cin>>n;
    cout<<"\nThe prime Factors are ";
    prime_fact(n);
    return 0;
}