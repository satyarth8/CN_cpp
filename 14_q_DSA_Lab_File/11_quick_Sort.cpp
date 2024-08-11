#include <iostream>

using namespace std;

int partition(int arr[], int start , int end)
{
  int pivot = arr[end];
  int i= start -1;

  for(int j=start; j<=end-1 ;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      int temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
    }
  }
  i++;
  int temp=arr[i];
  arr[i]=arr[end];
  arr[end]=temp;
  return i;
}

void quickSort(int arr[] , int start, int end)
{
  // base case
  if(end<=start)
    return;
  int pivot = partition(arr, start, end);
  quickSort(arr, start, pivot-1);
  quickSort(arr,pivot+1,end);
}

int main() {
    int arr[10]={8,2,5,3,9,4,7,6,1};

    quickSort(arr,0,10);

   
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}