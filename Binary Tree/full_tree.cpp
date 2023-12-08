#include <iostream>
#include <cstdlib>  // Add this line for the exit function
using namespace std;

#define MAX 10

char tree[MAX];

void root(char c) {
    if(tree[0] != '\0') {
        cout << "There is already a root node";
        exit(1);
    } else {
        tree[0] = c;
    }
}

void right(char c, int parent) {
    if (tree[parent] == '\0') {
        cout << "Parent doesn't exist";
        exit(1);
    } else {
        tree[2 * parent + 2] = c;
    }
}

void left(char c, int parent) {
    if (tree[parent] == '\0') {
        cout << "Parent doesn't exist";
        exit(1);
    } else {
        tree[2 * parent + 1] = c;
    }
}


void print() {  // Add void before print()
    for(int i = 0; i < MAX; i++) {
        if(tree[i] == '\0') {
            cout << "*";
        } else {
            cout << tree[i];
        }
    }
}

int main() {
    root('a');
    right('c', 0);
    left('b', 0);
    right('e', 1);
    left('d', 1);
    print();
    return 0;
}
