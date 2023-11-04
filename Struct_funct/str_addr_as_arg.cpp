#include <iostream>

using namespace std;
struct point 
{
    int x;
    int y;
};
void print(struct point *p)
{
    cout<<p->x<<" "<<p->y<<endl;
}
int main()
 {
    struct point p1, p2;
    p1={1,2};
    p2={3,4};
    print(&p1);
    print(&p2);
    return 0;
}