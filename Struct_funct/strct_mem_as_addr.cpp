#include <iostream>

using namespace std;
struct charset
{
    char s;
    int i;
};
void keyValue(char *s, int *i)
{
    cin>>*s;
    cin>>*i;
}
int main() {
    int j;
    struct charset cs;
    keyValue(&cs.s,&cs.i);
    cout<<cs.s<<" "<<cs.i;
    return 0;
}