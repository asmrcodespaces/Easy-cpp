// A palindrome is a string of characters that is the same forward
// and backward. Typically, punctuation, capitalization, and
// spaces are ignored. For example, "Poor Dan is in a droop" is
// a palindrome. Write C++ program with functions:
// • To check whether a given string is palindrome or not using a stack
// • To remove spaces and punctuation, convert all characters to
//   lowercase, and then call the above palindrome-checking function
// • To print string in reverse order using stack

#include <iostream>
#include <string>
using namespace std;

class Stack
{
    char a[200];
    int top;

public:
    Stack() { top = -1; }

    void push(char c)
    {
        if (top < 199)
            a[++top] = c;
    }

    char pop()
    {
        if (top == -1)
            return '\0';
        return a[top--];
    }

    bool isEmpty() { return top == -1; }
};

// Check palindrome using stack
bool isPalindrome(string s)
{
    Stack st;
    int i;

    for (i = 0; i < (int)s.length(); i++)
        st.push(s[i]);

    // Popping gives characters in reverse order
    for (i = 0; i < (int)s.length(); i++)
    {
        if (s[i] != st.pop())
            return false;
    }
    return true;
}

// Remove spaces and punctuation, convert to lowercase, then check
bool cleanAndCheck(string s)
{
    string clean = "";

    for (int i = 0; i < (int)s.length(); i++)
    {
        char c = s[i];

        if (c >= 'A' && c <= 'Z')
            clean += c + 32;  // to lowercase
        else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            clean += c;
        // spaces and punctuation are skipped
    }

    cout << "Cleaned string: " << clean << endl;
    return isPalindrome(clean);
}

// Print string in reverse using stack
void printReverse(string s)
{
    Stack st;

    for (int i = 0; i < (int)s.length(); i++)
        st.push(s[i]);

    cout << "Reversed string: ";
    while (!st.isEmpty())
        cout << st.pop();
    cout << endl;
}

int main()
{
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    printReverse(s);

    if (cleanAndCheck(s))
        cout << "The string is a palindrome" << endl;
    else
        cout << "The string is not a palindrome" << endl;

    return 0;
}
