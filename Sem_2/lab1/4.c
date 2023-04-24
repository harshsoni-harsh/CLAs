#include <stdio.h>
#define Max_size 100

int top = -1;
int stack[Max_size];

int isFull(){
    return top==Max_size;
}
int isEmpty(){
    return top==-1;
}
void push(int data){
    if(isFull()){
        printf("Stack is Full!\n");
    }
    else{
        stack[++top]=data;
    }
}
int pop(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return 0;
    }
    char x=stack[--top];
    return x;
}
int peek(){
    if(!isEmpty){
        return stack[top];
    }
    return 0;
}
void read(){
    int x;
    printf("Enter 5 numbers: \n");
    for (int i=0; i<5; i++){
        scanf("%d", &x);
        push(x);
    }
}
void calc(){
    int avg=0;
    int temp=top;
    int sum=0, max=peek(), min=peek();
    for (int i=0; i<5; i++){
        int p=pop();
        sum+=p;
        if(max<p){
            max=p;
        }
        if(min>p){
            min=p;
        }
    }
    top=temp;
    push(sum);
    push(avg);
    push(max);
    push(min);
    avg=sum/5;
    printf("Sum is %d\n", sum);
    printf("Average is %d\n", avg);
    printf("Max is %d\n", max);
    printf("Min is %d\n", min);
    printf("\n");
}
int main(){
    read();
    calc();
}