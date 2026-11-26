#include <stdio.h>

int main() {
    char *name[] = {
        "Nikhita", "Aboli", "Megha",
        "Sanika", "Pratik", "Saurabh"
    };

    int i, j, k, count = 0;

    printf("Possible Committees:\n");

    for(i = 0; i < 6; i++) {
        for(j = i + 1; j < 6; j++) {
            for(k = j + 1; k < 6; k++) {
                printf("%s, %s, %s\n",
                       name[i], name[j], name[k]);
                count++;
            }
        }
    }

    printf("\nTotal Committees = %d", count);

    return 0;
}
