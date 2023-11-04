#include <iostream>
#include <cstring>
using namespace std;

bool pal_str(char str[], int size, int ctr = 0)
{
    if (ctr >= size / 2)
    {
        return true;  // The string is a palindrome
    }

    if (str[ctr] != str[size - ctr - 1])
    {
        return false; // The string is not a palindrome
    }

    return pal_str(str, size, ctr + 1);
}

int main()
{
    char str[] = "racecar"; // Change this to the string you want to check
    int size = strlen(str);

    if (pal_str(str, size))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
