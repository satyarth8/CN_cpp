#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    float price;

public:
    Book(string t, string a, float p) : title(t), author(a), price(p) {}

    // Method to display details of the book
    void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: Rs " << price << endl;
    }

    // Method to apply discount to the price
    void applyDiscount(float percentage) {
        price -= price * (percentage / 100);
    }
};

int main() {
    Book myBook("Harry Potter", "J.K Rowling", 49.99);

    cout << "Book details before discount:" << endl;
    myBook.displayDetails();

    myBook.applyDiscount(10); // Applying 10% discount

    cout << "\nBook details after discount:" << endl;
    myBook.displayDetails();

    return 0;
}
