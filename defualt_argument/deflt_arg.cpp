#include<iostream>
using namespace std;
void print(int a,int b=0)
{
    cout<<a<<endl;
    cout<<b<<endl;
}
int main()
{
    print(10,1);
    print(120);
    return 0;
}