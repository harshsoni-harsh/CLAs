#include <stdio.h>

int main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Doing calculations\n");
    int num, verify=1;
    while(verify<size-1){
        for(int i=0; i<size-1;i++){
            if(arr[i]<=arr[i+1]){
                verify+=1;
            }
            else{
                num=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=num;
                verify=0;
            }
        }
    }
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}