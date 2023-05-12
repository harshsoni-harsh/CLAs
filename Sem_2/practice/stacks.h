#include <stdio.h>


#define MAX 50

typedef struct stacks
{
    int arr[MAX];
    int top;
    int bot;
    int max;
}
stack;



int pop(stack *temp);
void push(stack *temp, int a);
void display(stack temp);
int peek(stack temp);
int isfull(stack temp);
int isempty(stack temp);


int pop(stack *temp)
{
    return temp->arr[(temp->top)--];
}


void push(stack *temp, int a)
{
    temp->arr[++(temp->top)] = a;
    return;
}

void display(stack temp)
{
    do
    {
        printf("%d\n", temp.arr[(temp.top)]);
        temp.top = temp.top - 1;
    }
    while (!isempty(temp));
}
int peek(stack temp)
{
    return temp.arr[temp.top];
}

int isfull(stack temp)
{
    return temp.top == temp.max - 1 ? 1 : 0;
}

int isempty(stack temp)
{
    return temp.top == - 1 ? 1 : 0;
}