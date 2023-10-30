#include <iostream>
using namespace std;
void till_n(int n)
{
    
    if(n==0)
    {
        return ;
    }
    till_n(n-1);
    cout<<n<<" ";
    return;
}

int main() 
{
    int n;
    cout<<"enter the no.";
    cin>>n;
    till_n(n);
    return 0;
}
