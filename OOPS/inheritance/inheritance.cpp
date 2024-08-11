#include <iostream>
using namespace std;
class Shape {
public:
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() {
        return 3.14 * radius * radius;
    }

    double calculatePerimeter() {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Circle c(5);
    Rectangle r(3, 4);

    cout << "Circle area: " << c.calculateArea() << endl;
    cout << "Circle perimeter: " << c.calculatePerimeter() << endl;
    cout << "Rectangle area: " << r.calculateArea() << endl;
    cout << "Rectangle perimeter: " << r.calculatePerimeter() << endl;

    return 0;
}