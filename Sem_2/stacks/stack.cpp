#include <iostream>
#define max_size 5

using namespace std;

int stack[5];
int top = -1;

int isFull()
{
    if (top == max_size - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push (int data)
{
    if (!isFull())
        stack[++top] = data;
    else
        cout << "\nStack is Full\n";
}
int pop()
{
    if (!isEmpty())
    {
        cout << "\nPopped value is: " << stack[top--] << endl;
        return 1;
    }
    else
    {
        cout << "\nStack is Empty\n";
        return 0;
    }
}
int peek()
{
    if (isEmpty())
        return stack[top];
    else
        return 0;
}

int main()
{
    int o=1, x;
    while (o==1 || o==2 || o==3)
    {
        cout << "\nType 1-Pushing a value\nType 2-Popping a value\nType 3-Displaying the stack\n";
        cin >> o;
        if (o == 1)
        {
            cout << "\nEnter the value to push: ";
            cin >> x;
            push(x);
        }
        else if (o == 2)
        {
            pop();
        }
        else if (o == 3)
        {
            cout << "\n--> ";
            for (int i = 0; i <= top; i++)
            {
                cout << stack[i] << " ";
            }
            cout << "<--\n";
        }
        else
        {
            return 0;
        }
    }
}