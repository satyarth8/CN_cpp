#include <iostream>

using namespace std;

class Human
{
    public:
    string name;
    protected:
    int age , weight ;
};
class Student: public Human 
{
    int roll_number , fees;
};
int main() {
    // Your code here
    Student A;
    A.name="Satya";
    A.age=23;
    return 0;
}