#include <iostream>
#define MAX 100
using namespace std;

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int);
int dequeue();
int peek();
void print();
int isFull();
int isEmpty();

void enqueue(int data)
{
    if(isFull())
    {
        cout<<"Queue Overflow";
        exit(1);
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=data;
}
int dequeue()
{  
    if(isEmpty())
    {
        cout<<"Queue Underflow";
        exit(1);
    }
    int data=queue[front];
    front++;
    return data;
}
int isFull()
{
    if(rear==MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(front==-1||front==rear+1)
        return 1;
    else    
        return 0;
}
int peek()
{
    if(isEmpty())
    {
        cout<<" Queue Underflow ";
        exit(1);
    }
    return queue[front];
}
void print()
{
    int i=0;

    cout<<"Queue : "<<endl;
    for(i=front;i<=rear;i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int choice;
    while (true) {
        cout << "1. Insertion\n";
        cout << "2. Deletion\n";
        cout << "3. Print first element\n";
        cout << "4. Print all the elements\n";
        cout << "5. Quit\n";
        cout << "Enter your Choice: \n";
        cin >> choice;

        int data;
        switch (choice) {
            case 1:
                {
                cout << "Enter the element to enqueue: ";
                cin >> data;
                enqueue(data);
                cout << data << " Enqueued.\n";
                break;
                }
            case 2:
                {
                data = dequeue();
                cout << "Deleted element is: " << data << "\n";
                break;
                }
            case 3:
                {
                cout << "The first element of the queue is: " << peek() << "\n";
                break;
                }
            case 4:
                {
                print();
                break;
                }
            case 5:
                exit(1);
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}