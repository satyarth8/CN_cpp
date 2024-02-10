#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* link;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int);
int dequeue();
int peek();
void print();
bool isEmpty();

void enqueue(int n) {
    Node* temp = new Node;
    if (!temp) {
        cerr << "Memory Allocation Failed!\n";
        exit(EXIT_FAILURE);
    }
    temp->data = n;
    temp->link = nullptr;

    if (!front && !rear) {
        front = temp;
        rear = temp;
    } else {
        rear->link = temp;
        rear = temp;
    }
}

int dequeue() {
    if (isEmpty()) {
        cerr << "Error: Attempted to Dequeue From An Empty Queue!\n";
        exit(EXIT_FAILURE);
    }
    int retVal = front->data;
    Node* oldFront = front;
    front = front->link;
    delete oldFront;
    return retVal;
}

int peek() {
    if (isEmpty()) {
        cerr << "Error: Peek At An Empty Queue!\n";
        exit(EXIT_FAILURE);
    }
    return front->data;
}

void print() {
    Node* curr = front;
    cout << "Queue Contents:\n[";
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->link != nullptr) cout << ", ";
        curr = curr->link;
    }
    cout << "]\n";
}

bool isEmpty() {
    return front == nullptr;
}

int main() {
    int choice;
    while (true) {
        cout << "1. Insertion\n";
        cout << "2. Deletion\n";
        cout << "3. Print First Element\n";
        cout << "4. Print All Elements\n";
        cout << "5. Quit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        int data;
        switch (choice) {
            case 1:
                cout << "Enter The Element To Enqueue: ";
                cin >> data;
                enqueue(data);
                cout << data << " Enqueued.\n";
                break;
            case 2:
                try {
                    data = dequeue();
                    cout << "Deleted Element Is: " << data << "\n";
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            case 3:
                try {
                    cout << "First Element Of The Queue Is: " << peek() << "\n";
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            case 4:
                print();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid Choice.\n";
        }
    }
    return 0;
}