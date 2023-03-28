#include <stdio.h>
#include <stdlib.h>

void main(){
    int *ptr;
    int n = 1;

    ptr = (int*) malloc(100 * sizeof(int));

    // int p=10;
    printf("%d \n", ptr);
}