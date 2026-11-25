// Department library has N books. Write C/C++ program to
// store the cost of books in array in ascending order. Books are
// to be arranged in descending order of their cost. Write
// function for:
// • Reverse the contents of array without using temporary array
// • Copy costs of books those with cost less than 500 in new
// array
// • Delete the duplicate entries using temporary array
// • Delete duplicate entries without using temporary array
// • Count number of books with cost more than 500

#include <stdio.h>

void display(int a[], int n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void reverse(int a[], int n) {
    int i, temp;
    for(i = 0; i < n / 2; i++) {
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

void copyLess(int a[], int n) {
    int b[100], i, k = 0;

    for(i = 0; i < n; i++)
        if(a[i] < 500)
            b[k++] = a[i];

    printf("Costs below 500: ");
    display(b, k);
}

void duplicateTemp(int a[], int *n) {
    int b[100], i, j, k = 0, found;

    for(i = 0; i < *n; i++) {
        found = 0;

        for(j = 0; j < k; j++)
            if(a[i] == b[j])
                found = 1;

        if(!found)
            b[k++] = a[i];
    }

    *n = k;

    for(i = 0; i < k; i++)
        a[i] = b[i];
}

void duplicateNoTemp(int a[], int *n) {
    int i, j, k;

    for(i = 0; i < *n; i++) {
        for(j = i + 1; j < *n; j++) {
            if(a[i] == a[j]) {
                for(k = j; k < *n - 1; k++)
                    a[k] = a[k + 1];

                (*n)--;
                j--;
            }
        }
    }
}

int main() {
    int a[100], b[100], n, m, i, count = 0;

    printf("Enter number of books: ");
    scanf("%d", &n);

    printf("Enter costs in ascending order:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    reverse(a, n);

    printf("Descending order: ");
    display(a, n);

    copyLess(a, n);

    for(i = 0; i < n; i++)
        if(a[i] > 500)
            count++;

    printf("Books costing more than 500: %d\n", count);

    for(i = 0; i < n; i++)
        b[i] = a[i];

    m = n;
    duplicateTemp(b, &m);

    printf("Duplicates removed using temp: ");
    display(b, m);

    duplicateNoTemp(a, &n);

    printf("Duplicates removed without temp: ");
    display(a, n);

    return 0;
}