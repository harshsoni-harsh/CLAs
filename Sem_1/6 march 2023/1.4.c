#include <stdio.h>

void matm(int m, int n, int a, int b, int arr1[m][n], int arr2[a][b]);

int main(){
    int u,v,x,y, input;
    printf("Enter the dimensions of arr1 and arr2: ");
    scanf("%d %d %d %d", &u, &v, &x, &y);
    int mat1[u][v], mat2[x][y];
    printf("Enter arr1: \n");
    for(int i=0; i<u; i++){
        for(int j=0; j<v; j++){
            scanf("%d", &input);
            mat1[i][j]=input;
        }
    }
    printf("Enter arr2: \n");
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            scanf("%d", &input);
            mat2[i][j]=input;
        }
    }
    if(v==x){
        printf("\nMultiplication of matrix is: \n");
        matm(u,v,x,y,mat1,mat2);
    }
    else{
        printf("Arrays can't be multiplied\n");
    }
    return 0;
}
void matm(int m, int n, int a, int b, int arr1[m][n], int arr2[a][b]){
    int arr3[m][b];
    for(int i=0; i<m; i++){
        for(int j=0; j<b; j++){
            arr3[i][j]=0;
            for(int k=0; k<n; k++){
                arr3[i][j]+=arr1[i][k]*arr2[k][j];
            }
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }
}