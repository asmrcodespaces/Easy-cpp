#include <iostream>
using namespace std;

// paste your sort function(s) here
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    float arr[100];
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter percentages:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);          // or selectionSort / insertionSort / shellSort
    // quickSort(arr, 0, n - 1); // quick sort is called differently

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nTop 5: ";
    for (int i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << arr[i] << " ";
    return 0;
}
