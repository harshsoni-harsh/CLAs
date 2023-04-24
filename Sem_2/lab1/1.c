#include <stdio.h>
#define Max_size 100

int top = -1, stack[Max_size];

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
void pop(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    printf("Popped data is %d\n", stack[--top]);
}
void display(){
    for (int i=top; i>=0; i--){
        printf("|%d|\n", stack[i]);
    }
}
int main(){
    int choice = 0;
    while (choice != 4){
        printf("Type 1-Push\nType 2-Pop\nType 3-Display\nType 4-Terminate\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: {
                printf("\nEnter data to push: ");
                int data;
                scanf("%d", &data);
                push(data);
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4:{
                return 0;
            }
            default: {
                printf("Invalid Operation\n");
            }
        }
        
    }
}