#include <iostream>
#include <cstdlib>
#define MAX 4
using namespace std;

int cqueue[MAX];
int front = -1;
int rear = -1;

void enqueue(int);
int dequeue();
int peek();
int isEmpty();
int isFull();
void print();

void enqueue(int data) {
    if (isFull()) {
        cout << "Queue Overflow\n";
        exit(1);
    }
    if (front == -1)
        front = 0;
    if(rear==MAX-1)
        rear=0;
    else
        rear=rear+1;
    cqueue[rear]=data;
}

int dequeue() {
    int data;
    if (isEmpty()) {
        cout << "Queue Underflow\n";
        exit(1);
    }
    data = cqueue[front];
    if (front == rear)
        front = rear = -1;
    else if (front ==MAX-1)
        front=0;
    else
        front = (front + 1) ;
    return data;
}

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int peek() {
    if (isEmpty()) {
        cout << "Queue underflow\n";
        exit(1);
    }
    return cqueue[front];
}
void print()
{
    int temp;
    if(isEmpty())
    {
        cout<<"Queue Underflow";
        exit(1);
    }
    temp= front;
    if(front<=rear)
    {
        while (temp<=rear)
        {
            cout<<cqueue[temp]<<" ";
            temp++;
            /* code */
        }
    }
    else
    {
        while(temp<=MAX-1)
        {
            cout<<" "<<cqueue[temp];
            temp++;
        }
        temp=0;
        while(temp<=rear)
        {
            cout<<" "<<cqueue[temp];
            temp++;
        }
    }
    cout<<"\n";
}

int main() {
    int choice, data;

    while (true) {
        cout << "1. Insertion\n";
        cout << "2. Deletion\n";
        cout << "3. Print first element\n";
        cout << "4. Print all the elements\n";
        cout << "5. Quit\n";
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> data;
                enqueue(data);
                cout << data << " Enqueued.\n";
                break;
            case 2:
                data = dequeue();
                cout << "Deleted element is: " << data << "\n";
                break;
            case 3:
                cout << "The first element of the queue is: " << peek() << "\n";
                break;
            case 4:
                print();
                break;
            case 5:
                exit(1);
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}
