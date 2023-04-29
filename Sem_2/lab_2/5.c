#include <stdio.h>
#include "stacks.h"
#include <ctype.h>

void main()
{
    struct stack *operator = (struct stack *) malloc(sizeof(struct stack));
    operator->top=-1;
    operator->size=20;
    operator->arr=(int *)malloc(sizeof(int)*operator->size);
    char string[100];
    int index=0;
    printf("Enter the expression:\n");
    scanf("%[^\n]s", string);
    for (int i=0; string[i]!='\0'; i++)
    {
        if(isalnum(string[i]))
        {
            continue;
        }
        else if(string[i]=='(')
        {
            push(operator, string[i]);
        }
        else if(string[i]==')')
        {
            while (operator->top!=-1 && peek(operator)!='(')
            {
                pop(operator);
            }
            pop(operator);
        }
    }
    int n=0;
    while(!isEmpty(operator))
    {
        if(peek(operator)=='(')
        {
            n=1;
            break;
        }
    }
    if(n==1)
    {
        printf("Paranthesis not balanced\n");
    }
    else
    {
        printf("Paranthesis balanced\n");
    }
    free (operator->arr);
    free(operator);
}