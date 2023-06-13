#include <stdio.h>
#include "stacks.h"
#include <ctype.h>

int precedence(char data)
{
    switch(data)
    {
        case '^':
            return 3;
        case '*':
        case '%':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return -1;
        default:
            printf("Invalid Character\n");
            return -2;
    }
}

void main()
{
    struct stack *operator = (struct stack *) malloc(sizeof(struct stack));
    operator->top=-1;
    operator->size=20;
    operator->arr=(int *)malloc(sizeof(int)*operator->size);

    char string[100];
    char postfix[100] = {0};
    int index=0;
    printf("Enter the expression:\n");
    scanf("%[^\n]s", string);
    for (int i=0; string[i]!='\0'; i++)
    {
        switch (string[i])
        {
            case '(':
                push(operator, string[i]);
                break;
            case ')':
                while (operator->top!=-1 && peek(operator)!='(')
                {
                    postfix[index++]=peek(operator);
                    pop(operator);
                }
                pop(operator);
                break;
            case '^':
            case '*':
            case '%':
            case '/':
            case '+':
            case '-':
                if (isEmpty(operator)){
                    push(operator, string[i]);
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
                break;
            default:
                if(isalnum(string[i])){
                    postfix[index++]=string[i];
                }
                else
                {
                    printf("Invalid Character\n");
                }
                break;
        }
        /*               
            printf("%c, ", string[i]);
            for (int j =0; j<=operator
            ->top; j++){printf("%c", 
            operator->arr[j]);}printf(
            " %s\n", postfix);        
        */
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