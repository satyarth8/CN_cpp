#include <iostream>
using namespace std;
int exp(int x,int n)
{
    if(n==1)
    {
        return x;
    }
    return x*exp(x,(n-1));
}

int main() {
    int x, n;
   cout<<"enter the x value:";
   cin>>x;
   cout<<"enter the n value:";
   cin>>n;
   cout<<x<<" powered "<<n<<" = "<<exp(x,n);
    return 0;
}