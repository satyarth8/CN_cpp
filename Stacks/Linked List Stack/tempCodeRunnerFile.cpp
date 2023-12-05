#include <iostream>
#include<string.h>
using namespace std;

struct node{
    char data;
    struct node* link;
}*top=nullptr;
int isEmpty()
{
    if(top==nullptr)
        return 1;
    else
        return 0;
}
void push(char data)
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

char pop()
{
    node* temp;
    char val;
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

void are_bracket_proper(string s)
{
    int size=s.size();
    cout<<"size "<<size;
    for(int i=0;i<size;i++)
    {
        if(s[i]=='{' || s[i]=='('||s[i]=='[')
        {
            push(s[i]);
        }
        if(s[i]=='}'||s[i]==')'||s[i]==']')
        {
            if(pop()!=s[i])
            {
                cout<<"not proper";
                exit(1);
            }
        }
    }
    cout<<"all good the eqaution has proper bracket ";
}

int main() {

    string s;
    cout<<"Enter the string ";
    cin>>s;
    are_bracket_proper(s);
    return 0;
}