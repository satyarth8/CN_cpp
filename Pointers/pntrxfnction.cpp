#include<iostream>
using namespace std;
void print(int* p)
{
    cout<<*p<<endl;
}
void increment_ptr( int* p)
{
    p=p+1;
}
void increment_deref(int *p)
{
    (*p)++;
}
int main()
{
    int i=10;
    int *p=&i;
    print(p);

    cout<<p<<endl;
    increment_ptr(p);
    cout<<p<<endl;

    cout<<*p<<endl;
    increment_deref(p);
    cout<<*p<<endl;
}