#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

// function which adds the values at the end and returns the end pointer
node* create(node* tail, int value) {
    node* temp = new node;
    temp->data = value;
    temp->next = tail->next;
    tail->next = temp;
    return temp;  // Return the new tail
}

node* add_at_beg(node* tail, int val) {
    node* temp = new node;
    temp->data = val;
    temp->next = tail->next;
    tail->next = temp;
    return tail;  // No change in the tail when adding at the beginning
}

void print(node* tail) {
    node* temp = tail->next;
    do {
        cout << temp->data << endl;
        temp = temp->next;
    } while (temp != tail->next);
}

int main() {
    int n, val;
    node* tail = new node;
    tail->next = tail;  // Circular linked list, initially pointing to itself

    cout << "Enter the number of elements you want: ";
    cin >> n;

    cout << "Enter the value to be put at last: ";
    cin >> val;
    tail = create(tail, val);

    for (int i = 1; i < n; i++) {
        cout << "Enter the value to be added at the start: ";
        cin >> val;
        tail = add_at_beg(tail, val);
    }

    cout << "Circular Linked List:" << endl;
    print(tail);

    return 0;
}
