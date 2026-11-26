// Implement C++ program for expression conversion from infix
// to postfix and its evaluation using stack based on these
// conditions:
// • Operands and operators must both be single characters
// • Input postfix expression must be in a desired format
// • Only '+', '-', '*' and '/' operators are expected

#include <iostream>
#include <string>
using namespace std;

class CharStack
{
    char a[100];
    int top;

public:
    CharStack() { top = -1; }
    void push(char c) { a[++top] = c; }
    char pop() { return a[top--]; }
    char peek() { return a[top]; }
    bool isEmpty() { return top == -1; }
};

class FloatStack
{
    float a[100];
    int top;

public:
    FloatStack() { top = -1; }
    void push(float x) { a[++top] = x; }
    float pop() { return a[top--]; }
    bool isEmpty() { return top == -1; }
    int size() { return top + 1; }
};

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isOperand(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int precedence(char c)
{
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

// Convert infix to postfix using stack
string infixToPostfix(string infix)
{
    CharStack st;
    string postfix = "";

    for (int i = 0; i < (int)infix.length(); i++)
    {
        char c = infix[i];

        if (c == ' ')
            continue;
        else if (isOperand(c))
            postfix += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
                postfix += st.pop();
            if (!st.isEmpty())
                st.pop();  // remove '('
        }
        else if (isOperator(c))
        {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c))
                postfix += st.pop();
            st.push(c);
        }
    }

    while (!st.isEmpty())
        postfix += st.pop();

    return postfix;
}

// Evaluate postfix expression (operands must be single digits)
bool evaluatePostfix(string postfix, float &result)
{
    FloatStack st;

    for (int i = 0; i < (int)postfix.length(); i++)
    {
        char c = postfix[i];

        if (c >= '0' && c <= '9')
            st.push(c - '0');
        else if (isOperator(c))
        {
            if (st.size() < 2)
                return false;

            float b = st.pop();
            float a = st.pop();

            if (c == '+')
                st.push(a + b);
            else if (c == '-')
                st.push(a - b);
            else if (c == '*')
                st.push(a * b);
            else
            {
                if (b == 0)
                {
                    cout << "Error: division by zero" << endl;
                    result = 0;
                    return false;
                }
                st.push(a / b);
            }
        }
        else
            return false;  // letters cannot be evaluated
    }

    if (st.size() != 1)
        return false;

    result = st.pop();
    return true;
}

int main()
{
    string infix, postfix;
    float result;
    int choice;

    do
    {
        cout << "\n1. Infix to Postfix and evaluate\n";
        cout << "2. Evaluate a postfix expression\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter infix expression (e.g. 2+3*4 or a+b*c): ";
            cin >> infix;
            postfix = infixToPostfix(infix);
            cout << "Postfix expression: " << postfix << endl;

            if (evaluatePostfix(postfix, result))
                cout << "Result: " << result << endl;
            else
                cout << "Cannot evaluate (needs single-digit numbers, not letters)" << endl;
            break;

        case 2:
            cout << "Enter postfix expression (e.g. 234*+): ";
            cin >> postfix;

            if (evaluatePostfix(postfix, result))
                cout << "Result: " << result << endl;
            else
                cout << "Invalid postfix expression" << endl;
            break;

        case 3:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 3);

    return 0;
}
