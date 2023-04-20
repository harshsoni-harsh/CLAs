#include <stdio.h>

int fibonacci(int n);
int num1=0, num2=1;
int count=0;

void main(){
    int a;
    printf("Enter the length of fibonacci series \n");
    scanf("%d", &a);
    fibonacci(a);
}

int fibonacci(int n){
    if(2*count<n){
        printf("%d ", num1);
        (count!=n)?printf("%d ", num2):printf("\n");
        num1+=num2;
        num2+=num1;
        count+=1;
        fibonacci(n);
    }
    else{
        return 0;
    }
}