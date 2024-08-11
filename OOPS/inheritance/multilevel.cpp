#include <iostream>

using namespace std;

class Person
{
    protected:
    string name;
    int age;
};
class Employee: public Person
{
    protected:
    int salary;
};
class Manager: public Employee
{
    protected:
    string department;
    int no_of_employee;
    public:
    Manager(string name, int age, int salary , string dept, int no_emp)
    {
        this->name=name;
        this->age=age;
        this->salary=salary;
        this->department=dept;
        this->no_of_employee=no_emp;
    }
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
        cout << "Number of Employees: " << no_of_employee << endl;
    }
};
int main() {
    Manager sp("Satya", 19, 34343, "cs/it", 2);
    sp.displayDetails();
    return 0;
}