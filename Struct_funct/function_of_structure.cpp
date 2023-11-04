#include <iostream>

using namespace std;
struct point{
    int x;
    int y;
};

struct point pre(struct point p)
{
    p.x++;
    p.y=p.x+2;
    return p;
};
void print(struct point p)
{
    cout<<p.x<<" "<<p.y<<endl;

}
int main() {
    struct point p1,p2;
    p1={1,2};
    p2={1,23};
    p1=pre(p1);
    p2=pre(p2);
    print(p1);
    print(p2);
    return 0;
}