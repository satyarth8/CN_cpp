#include <iostream>

using namespace std;
#define MAX 5
int stack1[MAX];
int stack2[MAX];

int top1=-1,top2=-1;


void enqueue(int);
int dequeue();
void push1(int);
void push2(int);
int pop1();
int pop2();
int peek();


void enqueue(int data)
{
    if(top1==MAX-1)
    {
        cout<<"Queue overflow";
        exit(1);
    }
    push1(data);
}

int dequeue()
{
    if(top1==-1 && top2==-1)
    {
        cout<<"Queue is empty";
        exit(1);
    }
    if(top2==-1)
    {
        while(top1!=-1)
        {
            push2(pop1());
        }
    }
    return pop2();
}
int pop1()
{
    return stack1[top1--]; // Decrement after returning the value
}

int pop2()
{
    return stack2[top2--]; // Decrement after returning the value
}

void push2(int data)
{
    if(top2 == MAX - 1)
    {
        cout << "Queue Full";
        exit(1);
    }
    stack2[++top2] = data; // Increment first, then assign
}

void print()
{
    // Print elements in stack2 (front of queue)
    for(int i = top2; i >= 0; i--)
    {
        cout << " " << stack2[i];
    }
    // If stack2 is empty, print elements in stack1 as continuation of queue
    if(top2 == -1)
    {
        for(int i = 0; i <= top1; i++)
        {
            cout << " " << stack1[i];
        }
    }
    cout << endl;
}

void push1(int data)
{
    top1=top1+1;
    stack1[top1]=data;
}




int main()
{
    int choice, data;
    while (1)
    {
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.Print" << endl;
        cout << "------------" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the Value" << endl;
            cin >> data;
            enqueue(data);
            break;
        case 2:
            cout << dequeue() << " Dequeued" << endl;
            break;
        case 3:
            print();
            break;
        case 4:
            exit(1);
        }
    }
    return 0;
}