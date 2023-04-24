//Storing two stacks in one array

#include <stdio.h>
#define Max_size 10

int top=-1, stack[Max_size], top1=Max_size;

int stack_empty1(){
    if(top!=-1)
        return 0;
    return 1;
}
int stack_empty2(){
    if(top1!=Max_size)
        return 0;
    return 1;
}
int stack_full(){
    if(top==top1-1 || top==top1+1){
        return 1;
    }
    return 0;
}
void push1(int data){
    if(!stack_full()) stack[++top]=data;
    else printf("Stack is full\n");
}
void push2(int data){
    if(!stack_full()) stack[--top1]=data;
    else printf("Stack is full\n");
}
void pop1(){
    if(stack_empty1) top--;
    else printf("Underflow1\n");
}
void pop2(){
    if(stack_empty2) top1++;
    else printf("Underflow2\n");
}

void main(){
    push1(3);
    push2(4);
    push1(3);
    push2(4);
    push1(3);
    push2(4);
    push1(3);
    push2(4);
    push1(3);
    push2(4);
    push1(3);
    push2(4);
}