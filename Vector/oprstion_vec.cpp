#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v1;
    v1 = {1, 2, 3, 4, 5};
    v1.push_back(1);
    for ( auto  x : v1) {
        cout << x ;
    }

    return 0;
}