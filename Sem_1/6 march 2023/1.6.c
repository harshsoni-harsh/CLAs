#include <stdio.h>

double fib(int n);

void main(){
    int x,a=0;
    printf("Enter the length of fibonacci series: ");
    scanf("%d", &x);
    for(int i=0; i<x; i++){
        if(a%13==0){
            printf("\n");
        }
        a++;
        printf("%0.0lf ", fib(i));
    }
    printf("\n");
}

double fib(int n){
    if(n<2) return n;
    return fib(n-1)+fib(n-2);
}