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
    }
}
int precedence(char data)
{
    if(data =='(')
    {
        return -1;
    }
    else if (data == '^')
    {
        return 3;
    }
    else if(data == '*' || data == '%' || data == '/')
    {
        return 2;
    }
    else if(data == '+' || data == '-')
    {
        return 1;
    }
    else{
        printf("Invalid symbol %c\n", data);
        return 0;
    }
}
void reverse(char *data)
{
    int len=0;
    for(; data[len]!='\0'; len++);
    struct stack *reverse=(struct stack *)malloc(sizeof(struct stack));
    reverse->top=-1;
    reverse->size=len;
    reverse->arr=(int *)malloc(sizeof(int)*len);
    for(int i=0; i<len; i++)
    {
        push(reverse, data[i]);
    }
    for(int i=0; i<len; i++)
    {
        data[i]=pop(reverse);
    }
    free(reverse->arr);
    free(reverse);
}
