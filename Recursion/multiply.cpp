#include <iostream>

using namespace std;
int multi(int x, int y)
{
    if(y==0)
    {
        return 0;
    }
    return x+multi(x,y-1);
}
int main() {
    // Your code here
    cout<<multi(12,3);
    return 0;
}