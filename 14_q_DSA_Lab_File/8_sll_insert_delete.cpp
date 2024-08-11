#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *next;
} *head = nullptr;

void insert_at_beginning(int data)
{
  Node *new_node = new Node;
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

void delete_at_beginning()
{
  if (head == NULL)
  {
    cout << "List is empty." << endl;
  }
  else
  {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

void delete_at_last()
{
  if(head==nullptr)
  {
    cout<<"The list is empty";
  }
  else 
  {
    Node* ptr=head;
    while(ptr->next->next!=nullptr)
    {
      ptr=ptr->next;
    }
    ptr->next=nullptr;
  }
}
void display()
{
  if (head == NULL)
  {
    cout << "List is empty." << endl;
  }
  else
  {
    Node *current = head;
    cout << "List elements: ";
    while (current != NULL)
    {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
}

int main()
{
  insert_at_beginning(10);
  insert_at_beginning(5);
  insert_at_beginning(1);
  insert_at_beginning(10);
  insert_at_beginning(5);
  insert_at_beginning(1);
  delete_at_last();
  display();
  delete_at_last();
  display();
  delete_at_beginning();
  display();
  return 0;
}