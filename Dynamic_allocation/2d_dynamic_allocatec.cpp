#include<iostream>
using namespace std;
int main()
{
    int **p =new int*[10];
    for(int i=0;i<10;i++)
    {
        p[i]=new int[20];
    }
    p[1][2]=23;
    cout<<p[1][2]<<endl;
}