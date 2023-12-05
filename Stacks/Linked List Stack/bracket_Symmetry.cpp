#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAX 100

using namespace std;

char stack_Arr[MAX];
int top = -1;

void push(char data) {
    if (top >= MAX - 1) {
        cout << "stack overflow";
        exit(1);
    }
    top++;
    stack_Arr[top] = data;
}

char pop() {
    if (top == -1) {
        cout << "stack underflow";
        return '\0';
    }
    char value = stack_Arr[top];
    top--;
    return value;
}

int match_char(char closing, char opening) {
    return (closing == ')' && opening == '(') || (closing == '}' && opening == '{') || (closing == ']' && opening == '[');
}

void are_bracket_proper(string s) {
    int size = s.size();
    for (int i = 0; i < size; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == -1 || !match_char(s[i], pop())) {
                cout << "Not proper";
                exit(1);
            }
        }
    }

    if (top == -1) {
        cout << "All good, the equation has proper brackets";
    } else {
        cout << "Not proper";
    }
}

int main() {
    string s;
    cout << "Give equation: ";
    cin >> s;
    are_bracket_proper(s);
    return 0;
}
