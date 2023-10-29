#include<iostream>
using namespace std;
int main()
{
int a[] = {13, 2, 3, 4};
int *x =a;
int *p = x++;
cout << *p << endl;

}