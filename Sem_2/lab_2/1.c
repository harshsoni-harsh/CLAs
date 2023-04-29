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
    char postfix[100];
    int index=0;
    printf("Enter the expression:\n");
    scanf("%[^\n]s", string);
    for (int i=0; string[i]!='\0'; i++)
    {
        if(isalnum(string[i]))
        {
            postfix[index++]=string[i];
        }
        else if(isEmpty(operator))
        {
            push(operator, string[i]);
        }
        else if(string[i]=='(')
        {
            push(operator, string[i]);
        }
        else if(string[i]==')')
        {
            while (operator->top!=-1 && peek(operator)!='(')
            {
                postfix[index++]=peek(operator);
                pop(operator);
            }
            pop(operator);
        }
        else if(precedence(string[i])>precedence(peek(operator)))
        {
            push(operator, string[i]);
        }
        else if(precedence(string[i]) <= precedence(peek(operator)))
        {
            while(!isEmpty(operator) && precedence(string[i]) <= precedence(peek(operator))) {
                postfix[index++]=pop(operator);
            }
            push(operator, string[i]);
        }
    }
    while(!isEmpty(operator))
    {
        postfix[index++]=pop(operator);
    }
    postfix[index]='\0';
    printf("%s\n", postfix);

    free (operator->arr);
    free(operator);
}