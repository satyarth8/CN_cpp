#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    // Default constructor
    Student() : name("Unknown"), rollNumber(0), marks(0.0) {}

    // Parameterized constructor
    Student(string n, int r, float m) : name(n), rollNumber(r), marks(m) {}

    // Getter for name
    string getName() const {
        return name;
    }

    // Setter for name
    void setName(string n) {
        name = n;
    }

    // Getter for rollNumber
    int getRollNumber() const {
        return rollNumber;
    }

    // Setter for rollNumber
    void setRollNumber(int r) {
        rollNumber = r;
    }

    // Getter for marks
    float getMarks() const {
        return marks;
    }

    // Setter for marks
    void setMarks(float m) {
        marks = m;
    }

    // Function to print student's details
    void printDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    // Create an object using the default constructor
    Student student1;
    cout << "Student 1 details (default constructor):" << endl;
    student1.printDetails();
    cout << endl;

    // Create an object using the parameterized constructor
    Student student2("John Doe", 123, 95.5);
    cout << "Student 2 details (parameterized constructor):" << endl;
    student2.printDetails();
    cout << endl;

    // Modify student1's details using setter functions
    student1.setName("Jane Smith");
    student1.setRollNumber(456);
    student1.setMarks(88.7);
    cout << "Student 1 details (after using setters):" << endl;
    student1.printDetails();

    return 0;
}
