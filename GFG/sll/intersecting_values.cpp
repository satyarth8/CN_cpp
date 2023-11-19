#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* add_to_end(Node*& head, Node*& last, int value)
{
    Node* newNode = new Node(value);
    if (last == nullptr)
    {
        head = newNode;
        last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
    return last; // Corrected to return the updated head
}
Node* findIntersection(Node* head1, Node* head2)
{
    Node* head3 = nullptr;
    Node* last = nullptr;
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr1 = ptr1->next;
        }
        else if (ptr1->data == ptr2->data)
        {
            last = add_to_end(head3, last, ptr1->data);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else
        {
            ptr2 = ptr2->next;
        }
    }

    if (head3 == nullptr)
    {
        // The intersection is empty, so return a null pointer
        return nullptr;
    }
    else
    {
        // The intersection is not empty, so return the head of the intersection list
        return head3;
    }
}
int main()
{
    // Example usage
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);

    Node* list2 = new Node(2);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Node* intersection = findIntersection(list1, list2);

    // Print the intersection list
    while (intersection != nullptr)
    {
        std::cout << intersection->data << " ";
        intersection = intersection->next;
    }

    return 0;
}