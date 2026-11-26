#include <iostream>
using namespace std;

// paste your sort function(s) here
void shellSort(float arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            float temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
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

    shellSort(arr, n);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nTop 5: ";
    for (int i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << arr[i] << " ";
    return 0;
}