#include <iostream>

using namespace std;
float dive(int a, int b)
{
 if (b==0)
 {
  throw" div by 0";
 }
 return a/b;
}
int main() {
    int a, b;
    int i=0;
    
    while(i!=-1)
    {cin>>i;
    cin>>a;
    cin>>b;
    try 
    {
        double div=dive(a,b);
        cout<<" The divsion of "<<a<<" and  "<<b<< "is"<<div<<endl;
    }
    catch(const char* error)
    {
        cout<<" There was a error called :"<<error<<endl;
    }
    }
    return 0;
}