#include <iostream>
using namespace std;

string replacePi(string input) {
    // Base case: if the input string is empty or has only one character, no replacement is needed.
    if (input.length() <= 1) {
        return input;
    }

    // Check if the current and next characters are "pi".
    if (input[0] == 'p' && input[1] == 'i') {
        // Replace "pi" with "3.14" and recursively process the rest of the string.
        return "3.14" + replacePi(input.substr(2));
    } else {
        // If no "pi" is found, keep the current character and recursively process the rest.
        return input[0] + replacePi(input.substr(1));
    }
}

int main() {
    string input;

    cout << "Enter a string: ";
    cin >> input;

    string result = replacePi(input);
    cout << "Result: " << result << endl;

    return 0;
}
