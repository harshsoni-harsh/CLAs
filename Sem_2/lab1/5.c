#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;
};

int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size;
}
int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}
void push(struct stack *ptr, int data)
{
    if (isFull(ptr))
    {
        printf("Stack is Full!\n");
    }
    else
    {
        ptr->arr[++(ptr->top)] = data;
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        return 0;
    }
    int x = ptr->arr[(ptr->top)--];
    return x;
}
int peek(struct stack *ptr)
{
    if (!isEmpty(ptr))
    {
        return ptr->arr[ptr->top];
    }
    return 0;
}
void display(struct stack *ptr)
{
    for (int i = ptr->top; i >= 0; i--)
    {
        printf("|%d|\n", ptr->arr[i]);
    }
    printf("\n");
}
void read_and_sort(struct stack *s1, struct stack *s2)
{
    int x;
    printf("Enter 5 numbers: \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &x);
        while (peek(s1) > x)
        {
            if (isEmpty(s1))
            {
                break;
            }
            int d = pop(s1);
            push(s2, d);
        }
        push(s1, x);
        while (!isEmpty(s2))
        {
            int d = pop(s2);
            push(s1, d);
        }
    }
}
void main()
{
    struct stack *stack1 = (struct stack *)malloc(sizeof(struct stack));
    struct stack *stack2 = (struct stack *)malloc(sizeof(struct stack));
    stack1->size = 20;
    stack2->size = 20;
    stack1->top = -1;
    stack2->top = -1;
    stack1->arr = (int *)malloc(stack1->size * sizeof(int));
    stack2->arr = (int *)malloc(stack2->size * sizeof(int));

    read_and_sort(stack1, stack2);
    display(stack1);
    free(stack1->arr);
    free(stack2->arr);
}