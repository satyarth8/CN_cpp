#include <iostream>

using namespace std;
struct point
{ // pointer stucture
    int x;
    int y;
};
struct point* fun(int a, int b)
{ // we allocated memory for the structure
    struct point *ptr=(struct point *) malloc (sizeof(struct point));
    // made changes to values we accepted to put in the structure
    ptr->x=a;
    ptr->y=b+5;
    // assigned the value to the ptr1 and ptr2
    return ptr;
};
void print(struct point *ptr)
{
    cout<<ptr->x;
    cout<<ptr->y<<endl;
}
int main() {
    struct point *ptr1,*ptr2;
    ptr1=fun(2,3);
    ptr2=fun(6,9);
    print(ptr1);
    print(ptr2);
    free(ptr1);
    free(ptr2);
    return 0;
}