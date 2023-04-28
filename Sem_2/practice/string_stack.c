#include <stdio.h>
#include <string.h>
#define Max_size 100

char stack[Max_size], top = -1;

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull()
{
    if (top == Max_size - 1)
    {
        return 1;
    }
    return 0;
}
char pop()
{
    if (!isEmpty())
    {
        return stack[top--];
    }
    printf("Stack is Empty\n");
    return '\0';
}
void push(char x)
{
    if (!isFull())
    {
        stack[++top] = x;
    }
}
void reverse(char *t)
{
    int num=0;
    for (int i = 0; t[i] != '\0'; i++)
    {
        push(t[i]);
        num++;
    }
    for (int i = 0; i < num; i++)
    {
        t[i] = pop();
    }
}
int palindrome(char *t){
    while(!isEmpty()){
        pop();
    }
    for (int i=0; t[i]!='\0'; i++){
        push(t[i]);
    }
    for (int i=0; i<=top; i++){
        if(t[i]!=pop()){
            return 0;
        }
    }
    return 1;
}
void main()
{
    char let[] = "racecars";
    // reverse(let);
    if(palindrome(let)){
        printf("It is a palindrome\n");
    }
    else{
        printf("Not a palindrome\n");
    }
}
