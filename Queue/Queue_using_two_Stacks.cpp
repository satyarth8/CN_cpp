#include <iostream>

using namespace std;

void push(int data, int stack[], int* top);
int pop(int stack[], int* top);
void print(int stack[], int* top);
void enqueue(int data);
int dequeue();

#define MAX 100
int stack1[MAX];
int stack2[MAX];
int top1 = -1, top2 = -1;

void push(int data, int stack[], int* top)
{
    if (*top > MAX - 1)
    {
        cout << "Stack full" << endl;
        exit(1);
    }
    (*top)++;
    stack[*top] = data;
}

int pop(int stack[], int* top)
{
    int val = stack[*top - 1];
    (*top)--;
    return val;
}

void print(int stack[], int* top)
{
    for (int i = 0; i <= *top; i++)
    {
        cout << stack[i] << " ";
    }
}

void enqueue(int data)
{
    push(data, stack2, &top2);
}

int dequeue()
{
    int val;
    if (top1 == -1)
    {
        if (top2 == -1)
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        while (top2 != -1)
        {
            push(pop(stack2, &top2), stack1, &top1);
        }
        val = pop(stack1, &top1);
    }
    else
    {
        val = pop(stack1, &top1);
    }
    return val;
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
            print(stack1, &top1);
            break;
        case 4:
            exit(1);
        }
    }
    return 0;
}