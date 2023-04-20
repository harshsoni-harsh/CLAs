#include <stdio.h>

int fib(int n);

void main(){
    int x;
    printf("Enter the number: ");
    scanf("%d", &x);
    printf("0 ");
    for(int i=0; i<x; i++){
        printf("%d ",fib(i));
    }
    printf("\n");
}
int fib(int n){
    if(n<2)
    return 1;
    return fib(n-1)+fib(n-2);
}