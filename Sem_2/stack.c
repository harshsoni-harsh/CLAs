#include <stdio.h>

#define max_size 5

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
        printf("\nStack is Full\n");
}
int pop()
{
    if (!isEmpty())
    {
        printf("\nPopped value is: %d\n", stack[top--]);
        return 1;
    }
    else
    {
        printf("\nStack is Empty\n");
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

void main()
{
    int o=1, x;
    while (o==1 || o==2 || o==3)
    {
        printf("\nType 1-Pushing a value\nType 2-Popping a value\nType 3-Displaying the stack\n");
        scanf("%d", &o);
        if (o == 1)
        {
            printf("\nEnter the value to push: ");
            scanf("%d", &x);
            push(x);
        }
        else if (o == 2)
        {
            pop();
        }
        else if (o == 3)
        {
            printf("\n--> ");
            for (int i = 0; i <= top; i++)
            {
                printf("%d ", stack[i]);
            }
            printf("<--\n");
        }
        else
        {
            return;
        }
    }
}