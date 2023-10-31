#include <iostream>
using namespace std;
int find_x(int arr[],int size, int x,int index=0,int lastin=-1)
{
    
    if(size==0)
    {
        if(lastin!=-1)
        {
            return lastin;
        }
        return -1;
    }
    if(arr[0]==x)
    { 
        lastin=index;
    }
    
    return find_x(arr+1,size-1,x,index+1,lastin);
}
int main() 
{
    // Your code here
    int x=2;
    int arr[8]={1,2,434,2,344,344,23423,344};
    cout<<"Value present at"<<find_x(arr,8,x);
    return 0;
}