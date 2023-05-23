#include <stdio.h>

int main(){
    int x=3,y=3;
    int arr[x][y];
    printf("\nInput the array\n");
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nYour input array\n");
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    int det;
    det=
            arr[0][0]*(arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1])-
            arr[0][1]*(arr[1][0]*arr[2][2]-arr[2][0]*arr[1][2])+
            arr[0][2]*(arr[1][0]*arr[2][1]-arr[2][0]*arr[1][1]);
    printf("Determinant is %d\n", det);
    return 0;
}