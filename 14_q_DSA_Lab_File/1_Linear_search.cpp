#include <iostream>

using namespace std;

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int index=-1;
  int target = 4;

  for (int i = 0; i < 5; i++) 
  {
    if (arr[i] == target) {
       cout << "Target found at index: " << i << endl;
       index=i;
    }
  }
  if (index == -1) 
  {
    cout << "Target not found." << endl;
  }

}