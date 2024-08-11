#include <iostream>

using namespace std;

class Employee 
{
    private:
        string name;
        int age;
        double salary;
    public:
        void set_emp(string n,int a, double s)
        {
           name=n;
            age=a;
            salary=s;
        }
        void get_emp()
        {
            cout<<"Name="<<name<<endl;
            cout<<"Age="<<age<<endl;
            cout<<"Salary="<<salary<<endl;
        }
};
int main() {
    Employee x;
    x.set_emp("Satyartha Prakash",20,20000);
    x.get_emp();
    return 0;
}