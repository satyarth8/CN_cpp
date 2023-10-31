#include <iostream>
using namespace std;
int find_x(int arr[],int size, int x)
{

    if(size==0)
    {
        return -1;
    }
    if(arr[0]==x)
    {
        return arr[0];
    }
    return find_x(arr+1,size-1,x);
}
int main() 
{
    // Your code here
    int x=4348;
    int arr[5]={1,2,434,34,344};
    cout<<"Value present at"<<find_x(arr,5,x);
    return 0;
}