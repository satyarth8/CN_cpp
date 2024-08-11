#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *prev;
  Node *next;
}*head =nullptr;

  void insert_at_beginning(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL) {
      head->prev = new_node;
    }
    head = new_node;
  }

  void insert_at_end(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
      new_node->prev = NULL;
      head = new_node;
    } else {
      Node *current = head;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = new_node;
      new_node->prev = current;
    }
  }

  void delete_at_beginning() {
    if (head == NULL) {
      cout << "List is empty." << endl;
    } else {
      Node *temp = head;
      head = head->next;

      if (head != NULL) {
        head->prev = NULL;
      }
      delete temp;
    }
  }

  void delete_at_end() {
    if (head == NULL) {
      cout << "List is empty." << endl;
    } else if (head->next == NULL) {
      delete head;
      head = NULL;
    } else {
      Node *current = head;
      while (current->next->next != NULL) {
        current = current->next;
      }
      delete current->next;
      current->next = NULL;
    }
  }

  void display() {
    if (head == NULL) {
      cout << "List is empty." << endl;
    } else {
      Node *current = head;
      cout << "List elements: ";
      while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
      }
      cout << endl;
    }
  }


int main() {

    insert_at_beginning(10);
    insert_at_end(20);
    insert_at_beginning(5);
    insert_at_end(30);

    display();

    delete_at_beginning();
    delete_at_end();

    display();

  return 0;
}