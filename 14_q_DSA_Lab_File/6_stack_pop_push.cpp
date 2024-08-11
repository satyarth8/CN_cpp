#include <iostream>

using namespace std;

#define MAX 100
int stack[MAX] = {};
int top = -1;

void push(int val)
{
    if(top >= MAX-1) 
    {
        cout << "Stack overflow\n";
        return;
    }
    top++;
    stack[top] = val;
}

int pop()
{
    if(top <= -1)
    {
        cout << "Stack underflow\n";
        return -1; 
    }
    int val = stack[top];
    top--;
    return val;
}

void print()
{
    cout << "\nThe stack values are: ";
    for(int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice = 0, push_val, pop_val;

    while(choice != -1)
    {
        cout << "\n*********** MENU *************\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Print:\n";
        cout << "Enter choice: (-1 to exit) ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
                cout << "\nEnter the value to push: ";
                cin >> push_val;
                push(push_val);
                cout << "\nSuccess in pushing value!\n";
                break;
            case 2:
                pop_val = pop();
                cout << "\nThe value popped is: " << pop_val << endl;
                break;
            case 3:
                print();
                break;
            default:
                if(choice == -1)
                    cout << "Exited successfully.\n";
                else
                    cout << "\nPlease enter a correct option.\n";
                break;
        }
    }

    return 0;
}