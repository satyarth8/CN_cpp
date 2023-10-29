#include<iostream>
using namespace std;
int main()
{
    int *p=new int[10];
    cout<<sizeof(p);
    *p=12;
    *(p+1)=23;
    cout<<*p<<*(p+1);

}