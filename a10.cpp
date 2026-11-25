// Write C++ program for string operations—copy, concatenate,
// check substring, equal, reverse and length.


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[100], str2[100], str3[200];
    char sub[100], rev[100];

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    // Copy string
    strcpy(str3, str1);
    cout << "\nCopied string: " << str3;

    // Concatenate strings
    strcpy(str3, str1);
    strcat(str3, str2);
    cout << "\nConcatenated string: " << str3;

    // Substring
    cout << "\nEnter substring: ";
    cin >> sub;

    if (strstr(str1, sub) != NULL)
        cout << "Substring found";
    else
        cout << "Substring not found";

    // Compare strings
    if (strcmp(str1, str2) == 0)
        cout << "\nStrings are equal";
    else
        cout << "\nStrings are not equal";

    // Reverse string
    int len = strlen(str1);

    for (int i = 0; i < len; i++)
        rev[i] = str1[len - 1 - i];

    rev[len] = '\0';

    cout << "\nReversed string: " << rev;

    // Length
    cout << "\nLength: " << len;

    return 0;
}