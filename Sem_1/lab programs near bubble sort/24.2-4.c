#include <stdio.h>

int main(){
    int x,y;
    printf("Enter the dimensions of matrix: ");
    scanf("%d %d", &x, &y);
    int arr[x][y];
    int num=0;
    printf("\nEnter the matrix\n");
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            scanf("%d", &num);
            arr[i][j]=num;
        }
    }
    printf("\nPrinting transposed matrix\n");
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
    return 0;
}