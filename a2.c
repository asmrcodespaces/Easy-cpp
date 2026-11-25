// Write C/C++ program to store marks scored for first test of
// subject 'Data Structures and Algorithms' for N students.
// Compute:
// • The average score of class
// • Highest score and lowest score of class
// • Marks scored by most of the students
// • List of students who were absent for the test



#include <stdio.h>

int main() {
    int marks[100], n;
    int i, j, sum = 0;
    int highest = -1, lowest = 101;
    int freq, maxFreq = 0, mode = -1;
    int present = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter marks (-1 for absent):\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &marks[i]);

        if(marks[i] != -1) {
            sum += marks[i];
            present++;

            if(marks[i] > highest)
                highest = marks[i];

            if(marks[i] < lowest)
                lowest = marks[i];
        }
    }

    if(present == 0) {
        printf("All students are absent.");
        return 0;
    }

    printf("\nAverage = %.2f", (float)sum / present);
    printf("\nHighest = %d", highest);
    printf("\nLowest = %d", lowest);

    for(i = 0; i < n; i++) {
        if(marks[i] == -1)
            continue;

        freq = 0;

        for(j = 0; j < n; j++) {
            if(marks[i] == marks[j])
                freq++;
        }

        if(freq > maxFreq) {
            maxFreq = freq;
            mode = marks[i];
        }
    }

    printf("\nMost frequent marks = %d", mode);

    printf("\nAbsent students:\n");

    for(i = 0; i < n; i++) {
        if(marks[i] == -1)
            printf("Student %d\n", i + 1);
    }

    return 0;
}