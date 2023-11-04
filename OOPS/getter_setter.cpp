#include <iostream>

using namespace std;
class Student{
    public:
        int rollNumber;
    private:
        int age;
    public:
        void display()
        {
            cout<<age<<" "<<rollNumber;
        }
}

int main() {
    // Your code here
    return 0;
}