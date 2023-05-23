#include <stdio.h>

int main(){
    int size, search, input, found;
    printf("Enter the size of the array: \n");
    scanf("%d", &size);
    int num[size];
    printf("\nEnter the array elements\n");
    for(int i=0; i<size; i++){
        scanf("%d", &input);
        num[i]=input;
    }
    printf("Enter the searching number: \n");
    scanf("%d", &search);
    for(int i=0; i<size; i++){
        if(num[i]==search){
            printf("The index of %d is %d\n", search, i);
            found=1;
            break;
        }
    }
    if(found==1){
        printf("Success\n");
    }
    else{
        printf("Failure \n");
    }
    return 0;
}
