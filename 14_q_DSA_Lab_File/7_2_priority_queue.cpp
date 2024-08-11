#include <iostream>

using namespace std;

struct Node {
    int data;
    int priority;
    Node* link;
};

Node* front = nullptr;

bool isEmpty() {
    return (front == nullptr);
}

void enqueue(int data, int priority) {
    Node* temp = new Node;
    temp->data = data;
    temp->priority = priority;
    temp->link = nullptr;

    if (isEmpty() || priority < front->priority) {
        // Add at the beginning
        temp->link = front;
        front = temp;
    } else {
        // Add in between
        Node* ptr = front;
        while (ptr->link != nullptr && ptr->link->priority <= priority) {
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}

int dequeue() {
    Node* temp = front;
    if (isEmpty()) {
        cout << "The queue is empty." << endl;
        exit(1);
    }
    int data = front->data;
    cout << "Deleted element: " << front->data << " with priority: " << front->priority << endl;
    front = front->link;
    delete temp;
    return data;
}

void print() {
    Node* ptr = front;
    if (isEmpty()) {
        cout << "The queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    while (ptr != nullptr) {
        cout << ptr->data << ":" << ptr->priority << " , ";
        ptr = ptr->link;
    }
    cout << endl;
}

int main() {
    int choice, data, priority;
    while (true) {
        cout << "----------MENU----------" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print" << endl;
        cout << "4. Quit" << endl;
        cout << "-------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> data;
                cout << "Enter the priority: ";
                cin >> priority;
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                print();
                break;
            case 4:
                exit(1);
            default:
                cout << "Invalid input. Please try again." << endl;
        }
    }
    return 0;
}