// Write C++ program to store first year percentage of students
// in array. Sort array of floating-point numbers in ascending
// order using Quick Sort and display top five scores.

#include <iostream>
using namespace std;

int main()
{
    int a[100], stack[200];
    int n, i, j, temp;
    int top = -1;
    int low, high, pivot, p;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter percentages:\n";

    for (i = 0; i < n; i++)
        cin >> a[i];

    // Push starting and ending indexes
    stack[++top] = 0;
    stack[++top] = n - 1;

    // Quick Sort
    while (top >= 0)
    {
        high = stack[top--];
        low = stack[top--];

        pivot = a[high];
        i = low - 1;

        // Partition
        for (j = low; j < high; j++)
        {
            if (a[j] < pivot)
            {
                i++;

                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        p = i + 1;

        // Left part
        if (p - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        // Right part
        if (p + 1 < high)
        {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }

    cout << "\nSorted percentages:\n";

    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    // Top five students
    cout << "\n\nTop five percentages:\n";

    for (i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << a[i] << " ";

    return 0;
}