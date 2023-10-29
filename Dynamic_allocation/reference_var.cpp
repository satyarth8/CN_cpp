#include<iostream>
using namespace std;
int main()
{
    int i=10;
    int&j =i; // j is set to reference to i 
    j++; // it starts to behave like a copy of i
    cout<<j<<" "<< i<<endl;
    cout<<&j<<" "<<&i<<endl; // they share same address
}