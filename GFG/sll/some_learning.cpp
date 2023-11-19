#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};
// // Create nodes
// Node* node1 = new Node(42);
// Node* node2 = new Node(55);
// Node* node3 = new Node(67);

// // Connect nodes to form a linked list
// node1->next = node2;
// node2->next = node3;
// // ...

// // Note: You need to manage memory properly and free the allocated memory when you're done with the linked list.

int main() {
    // Struct Node* head3()=nullptr;
    // Node* node1=new  Node(10);
    // Node* node2=new  Node(20);
    // head3=node1;
    // node1->next=node2;
    // node2->next=nullptr;
    

    ///  
    // Initialize the head pointer
    Node* head = nullptr;

    // Create nodes
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);

    // Connect the nodes
    head = node1;
    node1->next = node2;
    // node2->next is already nullptr by default

    // Write the code to print the values using a while loop
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    // Clean up memory (optional but good practice)
    delete node1;
    delete node2;
    return 0;
}