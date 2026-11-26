// Write C++ program to store second year percentage of
// students in array. Write function for sorting array of
// floating-point numbers in ascending order using:
// a) Insertion Sort
// b) Shell Sort
// Display top five scores.

#include <iostream>
using namespace std;

int main()
{
    float a[100], b[100], key;
    int n, i, j, gap;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter percentages:\n";

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    // Insertion Sort
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    cout << "\nInsertion Sort:\n";

    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    // Shell Sort
    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (i = gap; i < n; i++)
        {
            key = b[i];
            j = i;

            while (j >= gap && b[j - gap] > key)
            {
                b[j] = b[j - gap];
                j = j - gap;
            }

            b[j] = key;
        }
    }

    cout << "\n\nShell Sort:\n";

    for (i = 0; i < n; i++)
        cout << b[i] << " ";

    // Top five students
    cout << "\n\nTop five percentages:\n";

    for (i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << a[i] << " ";

    return 0;
}