#include <iostream>

using namespace std;
int sum_arr(int arr[],int size)
{
    if(size==0)
    {
        return 0;
    }
    return arr[0]+sum_arr(arr+1,size-1);
}

int main() {
    int arr[5]={1,2,3,4};
    cout<<"SUm ="<<sum_arr(arr,5);
    return 0;
}