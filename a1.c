// In Second Year Computer Engineering class of M students,
// set A of students play cricket and set B of students play
// badminton. Write C/C++ program to find and display:
// • Set of students who play either cricket or badminton or both
// • Set of students who play both cricket and badminton
// • Set of students who play only cricket
// • Set of students who play only badminton
// • Number of students who play neither cricket nor badminton
// (Note: While realizing the set duplicate entries are to be
// avoided)

#include <stdio.h>

int main() {
    int M, n, x;
    int A[100], B[100];
    int i, j, found;
    int uni[100], inter[100], onlyC[100], onlyB[100];
    int u = 0, in = 0, c = 0, b = 0;

    printf("Enter total students: ");
    scanf("%d", &M);

    printf("Enter number of cricket players: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        found = 0;

        for(j = 0; j < c; j++)
            if(A[j] == x)
                found = 1;

        if(!found)
            A[c++] = x;
    }

    printf("Enter number of badminton players: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        found = 0;

        for(j = 0; j < b; j++)
            if(B[j] == x)
                found = 1;

        if(!found)
            B[b++] = x;
    }

    for(i = 0; i < c; i++) {
        uni[u++] = A[i];
    }

    for(i = 0; i < b; i++) {
        found = 0;

        for(j = 0; j < c; j++)
            if(B[i] == A[j])
                found = 1;

        if(found)
            inter[in++] = B[i];
        else
            uni[u++] = B[i];
    }

    for(i = 0; i < c; i++) {
        found = 0;

        for(j = 0; j < b; j++)
            if(A[i] == B[j])
                found = 1;

        if(!found)
            onlyC[c - 1 - (c - 1)] = A[i];
    }

    int oc = 0, ob = 0;

    for(i = 0; i < c; i++) {
        found = 0;
        for(j = 0; j < b; j++)
            if(A[i] == B[j])
                found = 1;
        if(!found)
            onlyC[oc++] = A[i];
    }

    for(i = 0; i < b; i++) {
        found = 0;
        for(j = 0; j < c; j++)
            if(B[i] == A[j])
                found = 1;
        if(!found)
            onlyB[ob++] = B[i];
    }

    printf("\nUnion: ");
    for(i = 0; i < u; i++)
        printf("%d ", uni[i]);

    printf("\nIntersection: ");
    for(i = 0; i < in; i++)
        printf("%d ", inter[i]);

    printf("\nOnly Cricket: ");
    for(i = 0; i < oc; i++)
        printf("%d ", onlyC[i]);

    printf("\nOnly Badminton: ");
    for(i = 0; i < ob; i++)
        printf("%d ", onlyB[i]);

    printf("\nNeither: %d", M - u);

    return 0;
}