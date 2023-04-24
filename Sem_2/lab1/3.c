#include <stdio.h>
#define Max_size 100

int top = -1;
char stack[Max_size];

int isFull(){
    return top==Max_size;
}
int isEmpty(){
    return top==-1;
}
void push(char data){
    if(isFull()){
        printf("Stack is Full!\n");
    }
    else{
        stack[++top]=data;
    }
}
char pop(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return 0;
    }
    char x=stack[--top];
    printf("Popped data is %c\n", x);
    return x;
}
void ispal(char *x){
    int len=0;
    for (len=0; x[len]!='\0'; len++);
    for (int i = 0; i<len; i++){
        push(x[i]);
    }
    for (int i = 0; i<len; i++){
        if(stack[len-i-1]!=x[i]){
            printf("The string is not a palindrome\n");
            return;
        }
    }
    printf("String is palindrome\n");
}
int main(){
    char x[]="abcba";
    ispal(x);
}