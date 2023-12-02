#include <iostream>
#define MAX 4

int stack_arr[MAX];
int top=-1;

using namespace std;
void push(int data)
{
    if(top-1==MAX)
    {
        cout<<"Stack overflow";
        return;
    }
    top++;
    stack_arr[top]=data;
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    return 0;
}
