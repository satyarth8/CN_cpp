#include <iostream>
#include<string.h>
using namespace std;

struct node{
    int data;
    struct node* link;
}*top=nullptr;
int isEmpty()
{
    if(top==nullptr)
        return 1;
    else
        return 0;
}
void push(int data)
{
    node*  temp=new node;
    if(temp==nullptr)
    {
        cout<<"stack overflow";
        exit(1);
    }
    temp->data=data;
    temp->link=nullptr;

    temp->link=top;
    top=temp;
}

int pop()
{
    node* temp;
    int val;
    if (isEmpty())
    {
        cout<<"stack underflow";
        exit(1);
    }
    temp=top;
    val=temp->data;
    top=top->link;
    free(temp);
    temp=nullptr;
    return val;
}

void palindrome_check(string s)
{
    int i=0;
    while(s[i]!='X')
    {
        push(s[i]);
        i++;
    }
    i++;
    while(s[i])
    {
        if(isEmpty()||s[i]!=pop())
        {
            cout<<"Not a palindrome";
            exit(1);
        }
        i++;
    }
    cout<<"Palindrome";
}
int main() {

    string s;
    cout<<"Enter the string ";
    cin>>s;
    palindrome_check(s);
    return 0;
}