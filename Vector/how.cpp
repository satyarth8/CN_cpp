#include <iostream>
#include<vector>

using namespace std;

int main() {
    // Your code here
    vector<int> myVec;
    myVec ={1,2,3,4,5};
    for(int i:myVec)
    {
        cout<<i<<endl;
    }
    return 0;
}