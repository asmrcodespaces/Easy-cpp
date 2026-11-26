#include <iostream>
using namespace std;

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    bubbleSort(arr, n);          // or selectionSort / insertionSort / shellSort
    // quickSort(arr, 0, n - 1); // quick sort is called differently

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nTop 5: ";
    for (int i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << arr[i] << " ";
    return 0;
}