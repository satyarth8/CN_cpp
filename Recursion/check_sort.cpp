#include <iostream>

using namespace std;

bool is_sorted(int a[],int size)
{
    if(size==0||size==1)
    {
        return true;
    }
    if(a[0]>a[1])
    {
        return false;
    }
    return is_sorted(a+1,size-1);
}
int main() {
    int arr[10]={1,2,3,4,5,6,99,8,9,11};
    cout<<(((is_sorted(arr,10))==1)?"true":"false");
    return 0;
}