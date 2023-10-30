#include <iostream>

using namespace std;
// int ctr=0;
// int ndigit(int n)
// {
//     if(n==0)
//     {
//         return ctr;
//     }
//     ndigit(n/10);
//     ctr++;
// }
int getDigits(int num) {
  if (num == 0) {
    return 1; // base case: 0 has 1 digit
  }

  int digits = 1 + getDigits(num / 10); // recursive case: number of digits in num / 10 + 1
  return digits;
}

int main() {
    cout<<getDigits(1233);
    return 0;
}