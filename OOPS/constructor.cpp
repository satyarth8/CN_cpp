#include <iostream>

using namespace std;

class Bank_Customer
{
    string name;
    int acc_no;
    int amount;
    public:
        static count()
        {
            static int customer_count=1;
            cout<<"\ncustomer count"<<customer_count++;
        }
        Bank_Customer() // Default Constructor
        {
            cout<<"\nDefault Constructor\n";
            count();
        }
        Bank_Customer(string name, int acc_no , int amount)//Parameterizedd Constructor
        {
            this->name=name;
            this->acc_no=acc_no;
            this->amount=amount;
            count();
        }
        void print_Info()
        {
            cout<<"\nName: "<<this->name<<"\nAcc no.: "<<this->acc_no<<"\nAmount: "<<this->amount;
        }
        Bank_Customer(Bank_Customer &B)
        {
            this->name=B.name;
            this->acc_no=B.acc_no;
            this->amount=0;
        }
    
};

int main() {
    Bank_Customer Satya;
    Bank_Customer Shiva("Shiva",21,9988);
    Bank_Customer Shiva_2(Shiva);
    Shiva.print_Info();
    cout<<"\n---copy---";
    Shiva_2.print_Info();
}