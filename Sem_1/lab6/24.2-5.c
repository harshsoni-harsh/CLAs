#include <stdio.h>

int main(){
    int x,y;
    printf("Enter the dimensions of matrix: ");
    scanf("%d %d", &x, &y);
    int arr[x][y], arr2[x*y];
    int num=0, num2=0,a=0;
    printf("\nEnter the matrix\n");
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            scanf("%d", &num);
            arr[i][j]=num;
            arr2[a]=num;
            a+=1;
        }
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<a-1; j++){
            if(arr2[j+1]<=arr2[j]){
                num2=arr2[j];
                arr2[j]=arr2[j+1];
                arr2[j+1]=num2;
            }
        }
    }
    a=0;
    printf("\nPrinting matrix in ascending order\n");
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            printf("%d ", arr2[a]);
            a++;
        }
        printf("\n");
    }
    printf("\nPrinting matrix in descending order\n");
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            a--;
            printf("%d ", arr2[a]);
        }
        printf("\n");
    }
    return 0;
}