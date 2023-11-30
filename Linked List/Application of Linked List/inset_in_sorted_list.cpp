#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* create(int val) {
    node* new_node = new node;
    new_node->data = val;
    new_node->next = nullptr;
    return new_node;
}

node* add_at_end(node* head, int val) {
    node* new_node = create(val);

    if (head == nullptr) {
        // If the list is empty, the new node becomes the head
        head = new_node;
    } else {
        // Traverse to the end of the list and add the new node
        node* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }

    return head;
}
node* add_in_sorted(node* head, int val) {
    node* temp = new node;
    temp->data = val;
    node* ptr = head;

    // If the list is empty or the new value is smaller than the head's data
    if (head == nullptr || val < head->data) {
        temp->next = head;
        return temp;
    }

    // Traverse the list to find the appropriate position
    while (head->next != nullptr && head->next->data < val) {
        head = head->next;
    }

    // Insert the new node
    temp->next = head->next;
    head->next = temp;

    return ptr;
}

void print(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n, val;
    node* head = nullptr;

    cout << "Enter the number of elements you want: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value to be added in the list: ";
        cin >> val;
        head = add_at_end(head, val);
    }

    cout << "Linked List:" << endl;
    print(head);
    int value;
    cout<<"Enter the value to add:"<<endl;
    cin>>value;
    cout<<endl;
    head=add_in_sorted(head,value);
    print(head);
    return 0;
}
