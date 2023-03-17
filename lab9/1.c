#include <stdio.h>

void swap(int *a, int *b);

void main(){
    int x, y;
    printf("Enter the values: ");
    scanf("%d %d", &x, &y);
    printf("Before swapping values are: %d %d \n", x,y);
    int* p=&x;
    int* q=&y;
    swap(p, q);
    printf("After swapping values are: %d %d \n", x,y);
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    printf("After swapping values are: %d %d ", *a,*b);
}