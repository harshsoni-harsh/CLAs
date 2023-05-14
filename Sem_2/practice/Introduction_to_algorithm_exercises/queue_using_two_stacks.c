#include "../c_libraries/stacks.h"
#include <stdlib.h>

void enqueue(stack *a, int data)
{
    push(a,data);
}
void dequeue(stack *a, stack *b)
{
    while(!isempty(*a))
    {
        push(b, pop(a));
    }
    pop(b);
    while(!isempty(*b))
        push(a,pop(b));
}
void display_queue(stack *a, stack *b)
{
    while(!isempty(*a))
        push(b,pop(a));
    display(*b);
    while(!isempty(*b))
        push(a,pop(b));
    printf("\n");
}

void main()
{
    stack *a = (stack *)malloc(sizeof(stack));
    stack *b = (stack *)malloc(sizeof(stack));
    a->top = -1;
    b->top = -1;
    a->max = 20;
    b->max = 20;
    a->arr = (int *)malloc(sizeof(int)*a->max);
    b->arr = (int *)malloc(sizeof(int)*b->max);
    enqueue(a, 5);
    enqueue(a, 4);
    enqueue(a, 3);
    display_queue(a,b);
    dequeue(a,b);
    display_queue(a,b);
    dequeue(a,b);
    display_queue(a,b);
    free(a->arr);
    free(a);
    free(b->arr);
    free(b);
}