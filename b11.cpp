// Second year Computer Engineering class, set A of students
// like Vanilla Ice-cream and set B of students like butterscotch
// ice-cream. Write C/C++ program to store two sets using
// linked list. Compute and display:
// • Set of students who like either vanilla or butterscotch or both
// • Set of students who like both vanilla and butterscotch
// • Set of students who like only vanilla, not butterscotch
// • Set of students who like only butterscotch, not vanilla
// • Number of students who like neither vanilla nor butterscotch

#include <iostream>
using namespace std;

struct Node
{
    int roll;
    Node *next;
};

// Check if roll number is present in list
bool search(Node *head, int x)
{
    while (head != NULL)
    {
        if (head->roll == x)
            return true;
        head = head->next;
    }
    return false;
}

// Insert at end (duplicates are skipped)
void insert(Node *&head, int x)
{
    if (search(head, x))
        return;

    Node *temp = new Node;
    temp->roll = x;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    Node *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
}

void display(Node *head)
{
    if (head == NULL)
        cout << "None";
    while (head != NULL)
    {
        cout << head->roll << " ";
        head = head->next;
    }
    cout << endl;
}

int count(Node *head)
{
    int c = 0;
    while (head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}

int main()
{
    Node *A = NULL, *B = NULL;
    Node *uni = NULL, *inter = NULL, *onlyA = NULL, *onlyB = NULL;
    int M, n, x, i;

    cout << "Enter total number of students: ";
    cin >> M;

    cout << "Enter number of students who like Vanilla: ";
    cin >> n;
    cout << "Enter roll numbers:\n";
    for (i = 0; i < n; i++)
    {
        cin >> x;
        insert(A, x);
    }

    cout << "Enter number of students who like Butterscotch: ";
    cin >> n;
    cout << "Enter roll numbers:\n";
    for (i = 0; i < n; i++)
    {
        cin >> x;
        insert(B, x);
    }

    // Union and only vanilla / intersection
    for (Node *p = A; p != NULL; p = p->next)
    {
        insert(uni, p->roll);
        if (search(B, p->roll))
            insert(inter, p->roll);
        else
            insert(onlyA, p->roll);
    }

    // Rest of union and only butterscotch
    for (Node *p = B; p != NULL; p = p->next)
    {
        insert(uni, p->roll);
        if (!search(A, p->roll))
            insert(onlyB, p->roll);
    }

    cout << "\nVanilla set: ";
    display(A);
    cout << "Butterscotch set: ";
    display(B);

    cout << "\nEither vanilla or butterscotch or both: ";
    display(uni);
    cout << "Both vanilla and butterscotch: ";
    display(inter);
    cout << "Only vanilla: ";
    display(onlyA);
    cout << "Only butterscotch: ";
    display(onlyB);
    cout << "Neither vanilla nor butterscotch: " << M - count(uni) << endl;

    return 0;
}
