#include <iostream>
using namespace std;

// paste your sort function(s) here
void quickSort(float arr[], int low, int high) {
    if (low < high) {
        float pivot = arr[high]; // Last element as pivot
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        float temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, n - 1);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nTop 5: ";
    for (int i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << arr[i] << " ";
    return 0;
}