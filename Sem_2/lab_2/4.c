#include <stdio.h>
#include "stacks.h"
#include <ctype.h>

void main()
{
    struct stack *symbol = (struct stack *) malloc(sizeof(struct stack));
    symbol->top=-1;
    symbol->size=20;
    symbol->arr=(int *)malloc(sizeof(int)*symbol->size);
    char string[100];
    int calc=0;
    printf("Enter the expression with space separated symbols:\n");
    scanf("%[^\n]s", string);
    reverse(string);
    for (int i=0; string[i]!='\0'; i++)
    {
        int c=0;
        while(string[i]!=' ' && isdigit(string[i]) && string[i]!='\n')
        {
            c=string[i++]-'0' + c*10;
        }
        if(c!=0)
        {
            push(symbol, c);
        }
        else if((string[i])=='0' || string[i]==' ')
        {
            continue;
        }
        else if(precedence(string[i])!=0)
        {
            if(symbol->top<1)
            {
                printf("Not enough operands!\n");
            }
            else
            {
                int a=pop(symbol);
                int b=pop(symbol);
                switch(string[i])
                {
                    case '+':
                        calc=b+a;
                        break;
                    case '-':
                        calc=b-a;
                        break;
                    case '*':
                        calc=b*a;
                        break;
                    case '/':
                        calc=b/a;
                        break;
                    case '%':
                        calc=b%a;
                        break;
                    case '^':
                        calc=(int)pow((double)b,(double)a);
                        break;
                    default:
                        break;
                }
                push(symbol, calc);
            }
        }
    }
    printf("%d\n", calc);
    free (symbol->arr);
    free(symbol);
}