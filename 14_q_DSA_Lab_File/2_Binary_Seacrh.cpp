#include <iostream>

using namespace std;

int binary_search(int arr[], int n, int target) {
  int low = 0;
  int high = n - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = 5;
  int target = 4;

  int index = binary_search(arr, n, target);

  if (index != -1) {
    cout << "Target found at index: " << index << endl;
  } else {
    cout << "Target not found." << endl;
  }

  return 0;
}