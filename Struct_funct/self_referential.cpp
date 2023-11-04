#include <iostream>

using namespace std;
struct code 
{
    int i;
    char c;
    struct code *ptr;
};
int main() {
    struct code v1,v2;
    v1={1,'a',&v2};
    v2={2,'b',NULL};
    cout<<v1.c<<endl;
    cout<<v1.ptr->c;
    // Your code here
    return 0;
}