#include <stdio.h>

void isprime(int n);

void main(){
    int x;
    printf("Enter the number: ");
    scanf("%d", &x);
    isprime(x);
}

void isprime(int n){
    int factor=0;
    for(int i=1; i<n; i++)
        if(n%i==0)
            factor+=1;
    if(factor==1)
        printf("\nIt is a prime number\n");
    else
        printf("\nIt is not a prime number\n");
}