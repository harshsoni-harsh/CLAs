#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    int size;
    int* arr;
};

int isFull(struct stack *ptr)
{
    return ptr->top==(ptr->size-1);
}
int isEmpty(struct stack *ptr)
{
    return ptr->top==(-1);
}
void push(struct stack *ptr, int data)
{
    if(isFull(ptr)){
        printf("Stack is Full!\n");
    }
    else{
        ptr->arr[++ptr->top]=data;
    }
}
int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack is empty!\n");
        return 0;
    }
    else
    {
        return (ptr->arr[ptr->top--]);
    }
}
int peek(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack is empty!\n");
    }
    else{
        return ptr->arr[ptr->top];
        //printf("%d\n", ptr->arr[ptr->top]);
    }
}
void display(struct stack *ptr)
{
    for (int i=0; i <= ptr->top; i++)
    {
        printf("|%d|  ", ptr->arr[i]);
    }
}