#include <iostream>

using namespace std;
struct Student
{
    string name;
    int age;
    int roll;
    float mark;
};
void print(string nam,int age, float roll,float cgpa)
{
    cout<<nam<<" "<<age<<" "<<roll<<" "<<cgpa<<" ";
}
int main() {
    // Your code here
    struct Student s1={"Satyarth Prakash",19,15,8.54};
    print(s1.name,s1.age,s1.mark,s1.roll);
    return 0;
}