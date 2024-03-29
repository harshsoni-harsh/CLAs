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
        else
        {
            printf("Precedence is %d for %c\n", precedence(string[i]), string[i]);
        }
    }
    
    free (operator->arr);
    free(operator);
}