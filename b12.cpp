// Write C++ program for storing binary number using doubly
// linked lists. Write functions:
// a) To compute 1's and 2's complement
// b) Add two binary numbers

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int bit;
    Node *prev, *next;
};

// Insert bit at end
void insertEnd(Node *&head, Node *&tail, int b)
{
    Node *temp = new Node;
    temp->bit = b;
    temp->next = NULL;
    temp->prev = tail;

    if (head == NULL)
        head = temp;
    else
        tail->next = temp;
    tail = temp;
}

// Insert bit at beginning
void insertBegin(Node *&head, Node *&tail, int b)
{
    Node *temp = new Node;
    temp->bit = b;
    temp->prev = NULL;
    temp->next = head;

    if (head == NULL)
        tail = temp;
    else
        head->prev = temp;
    head = temp;
}

// Store binary string in doubly linked list
void create(Node *&head, Node *&tail, string s)
{
    for (int i = 0; i < (int)s.length(); i++)
        insertEnd(head, tail, s[i] - '0');
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->bit;
        head = head->next;
    }
    cout << endl;
}

// 1's complement: flip every bit
void onesComplement(Node *head, Node *&h1, Node *&t1)
{
    while (head != NULL)
    {
        insertEnd(h1, t1, head->bit == 0 ? 1 : 0);
        head = head->next;
    }
}

// 2's complement: 1's complement + 1 (start from last bit)
void twosComplement(Node *t1, Node *&h2, Node *&t2)
{
    int carry = 1;
    for (Node *p = t1; p != NULL; p = p->prev)
    {
        int sum = p->bit + carry;
        insertBegin(h2, t2, sum % 2);
        carry = sum / 2;
    }
    // carry out of the leftmost bit is dropped (same number of bits)
}

// Add two binary numbers (start from last bits)
void add(Node *t1, Node *t2, Node *&hr, Node *&tr)
{
    int carry = 0;
    while (t1 != NULL || t2 != NULL || carry != 0)
    {
        int sum = carry;
        if (t1 != NULL)
        {
            sum += t1->bit;
            t1 = t1->prev;
        }
        if (t2 != NULL)
        {
            sum += t2->bit;
            t2 = t2->prev;
        }
        insertBegin(hr, tr, sum % 2);
        carry = sum / 2;
    }
}

bool isBinary(string s)
{
    if (s.length() == 0)
        return false;
    for (int i = 0; i < (int)s.length(); i++)
        if (s[i] != '0' && s[i] != '1')
            return false;
    return true;
}

int main()
{
    Node *head1 = NULL, *tail1 = NULL;
    Node *head2 = NULL, *tail2 = NULL;
    Node *oh = NULL, *ot = NULL;  // 1's complement
    Node *th = NULL, *tt = NULL;  // 2's complement
    Node *sh = NULL, *st = NULL;  // sum
    string s1, s2;

    cout << "Enter first binary number: ";
    cin >> s1;
    while (!isBinary(s1))
    {
        cout << "Invalid! Enter only 0 and 1: ";
        cin >> s1;
    }
    create(head1, tail1, s1);

    cout << "Binary number: ";
    display(head1);

    onesComplement(head1, oh, ot);
    cout << "1's complement: ";
    display(oh);

    twosComplement(ot, th, tt);
    cout << "2's complement: ";
    display(th);

    cout << "\nEnter second binary number to add: ";
    cin >> s2;
    while (!isBinary(s2))
    {
        cout << "Invalid! Enter only 0 and 1: ";
        cin >> s2;
    }
    create(head2, tail2, s2);

    add(tail1, tail2, sh, st);
    cout << "Addition: ";
    display(head1);
    cout << "        + ";
    display(head2);
    cout << "        = ";
    display(sh);

    return 0;
}
