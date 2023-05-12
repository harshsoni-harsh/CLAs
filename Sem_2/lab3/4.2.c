#include "stacks.h"

typedef struct stack stack;

void toh(int disk, stack* source, stack* dest, stack* aux)
{
    if(disk<=1)
    {
        push(dest, pop(source));
        return;
    }
    toh(disk-1, source, aux, dest);
    push(dest, pop(source));
    toh(disk - 1, aux, dest, source);
}
void main()
{
    int disks;    printf("Enter number of disks: ");    scanf("%d", &disks);
    stack* a=(stack*)malloc(sizeof(stack));
    stack* b=(stack*)malloc(sizeof(stack));
    stack* c=(stack*)malloc(sizeof(stack));
    a->top = -1;    b->top = -1;    c->top = -1;
    a->size = disks+1;    b->size = disks+1;    c->size = disks+1;
    a->arr = (int *)malloc(sizeof(int)*disks);
    b->arr = (int *)malloc(sizeof(int)*disks);
    c->arr = (int *)malloc(sizeof(int)*disks);
    for (int i=0; i<disks; i++)   push(a, i+1);
    printf("\nStack a:\n");        display(a);
    printf("\nStack b:\n");        display(b);
    printf("\nStack c:\n");        display(c);
    toh(disks, a,b,c);    
    printf("\nStack a:\n");        display(a);
    printf("\nStack b:\n");        display(b);
    printf("\nStack c:\n");        display(c);
    free(a->arr);                     free(a);
    free(b->arr);                     free(b);
    free(c->arr);                     free(c);
}