#include <stdio.h>
#include <ctype.h>
#define or ||
#define and &&

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

void main(){
    char seq[100];
    scanf("%s", seq);
    char op[100][10];
    int index=0, sub_index=0, num_index=0;
    char num[10];
    for (int i=0; seq[i+1]!='\0'; i++){
        if(isdigit(seq[i]))
        {
            num[num_index++]=seq[i];
        }
        // else if(seq[i]=='(' or seq[i]==')')
        else if(num_index!=0)
        {
            for (int j=0; j<num_index; j++)
            {
                op[index][sub_index++]=num[j];
            }
            op[index++][sub_index]='\0';
            num_index=0;
        }
    }
    printf("%d %d", index, sub_index);
    for (int i=0; i<index; i++){
        for (int j=0; j<sub_index; j++){
            printf("%c", op[i][j]);
        }
    }
}