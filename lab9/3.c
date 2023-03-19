#include <stdio.h>

void extreme(int* largest, int* smallest, int* p, int s);

void main(){
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the numbers\n");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    int num1=arr[0], num2=arr[0];
    int *n1=&num1, *n2=&num2, *n3=&arr[0];
    extreme(n1, n2, n3, size);
    printf("Largest is %d, smallest is %d\n", num1, num2);
}

void extreme(int* largest, int* smallest, int* p, int s){
    for(int i=0; i<s; i++){
        if(*largest<*(p+i)){
            *largest=*(p+i);
        }
        if(*smallest>*(p+i)){
            *smallest=*(p+i);
        }
    }
}