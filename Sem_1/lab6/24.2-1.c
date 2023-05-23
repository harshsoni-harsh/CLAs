#include <stdio.h>

int main(){
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[size];
    int num;
    printf("\nWrite the array: \n");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(arr[j+1]<=arr[j]){
                num=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=num;
            }
        }
    }
    printf("\n Printing sorted array: \n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}