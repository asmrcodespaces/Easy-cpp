// Write C++ program to store first year percentage of students
// in array. Write function for sorting array of floating-point
// numbers in ascending order using:
// a) Selection Sort
// b) Bubble Sort
// Display top five scores.


#include <iostream>
using namespace std;

int main()
{
    float a[100], b[100], temp;
    int n, i, j, min;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter percentages:\n";

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    // Selection Sort
    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    cout << "\nSelection Sort:\n";

    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    // Bubble Sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    cout << "\n\nBubble Sort:\n";

    for (i = 0; i < n; i++)
        cout << b[i] << " ";

    // Top five students
    cout << "\n\nTop five percentages:\n";

    for (i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << a[i] << " ";

    return 0;
}