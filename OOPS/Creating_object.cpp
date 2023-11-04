#include <iostream>

using namespace std;
class Student
{
    public:
        int rollNumber;
        int age;
};

int main() {
    //static
    Student s1;
    Student s2;
    Student s3,s4,s5;
    s1.age=24;
    s1.rollNumber=101;
    cout<<s1.age<<endl;
    cout<<s1.rollNumber<<endl;

    //dynamic
    Student *s6 = new Student;
    (*s6).age=23;
    (*s6).rollNumber=104;
    s6 -> age = 23;
    s6 -> rollNumber =104;
    cout<<(*s6).age<<endl;
    cout<<(*s6).rollNumb er<<endl;
    return 0;
}