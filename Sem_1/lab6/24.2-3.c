#include <stdio.h>

int main(){
    int x,y;
    printf("Enter the dimensions of matrix: ");
    scanf("%d %d", &x, &y);
    int arr[x][y],num=0;
    int even[30], odd[30], count_even=0, count_odd=0;
    printf("\nEnter the matrix\n");
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            scanf("%d", &num);
            arr[i][j]=num;
            if(num%2==0){
                even[count_even]=num;
                count_even++;
            }
            else{
                odd[count_odd]=num;
                count_odd++;
            }
        }
    }
    printf("\nPrinting even numbers\n");
    for(int i=0; i<count_even; i++){
        printf("%d ", even[i]);
    }
    printf("\nPrinting odd numbers\n");
    for(int j=0; j<count_odd; j++){
        printf("%d ", odd[j]);
    }
    printf("\n");
    return 0;
}