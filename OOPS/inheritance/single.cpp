#include <iostream>

using namespace std;
class Human
{
    protected:
    string name;
    int age;
    
};

class student : public Human 
{
    public:
    int roll,fees;

    student(string name, int age , int roll , int fees ) 
    {
        this->name=name;
        this->age=age;
        this->roll=roll;
        this->fees=fees;
    }
    void get_info()
    {
        cout<<name<<" "<<age<<" "<<roll<<" "<<fees<<" ";
    }
};
int main() {
    student sp("satya", 9, 34, 100);
    sp.get_info();
    return 0;
}