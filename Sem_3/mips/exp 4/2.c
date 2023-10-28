#include <stdio.h>
#include <stdlib.h>

int determinant(int **arr, int row, int col)
{
    if (row == 1)
    {
        return arr[0][0]; 
    }
    
    int det = 0;
    for (int i=0; i<row; i++)
    {
        int **temp = (int**)malloc(sizeof(int*)*(row-1));
        for (int j=1; j<row; j++)
        {
            int index=0;
            temp[j-1] = (int*)malloc(sizeof(int)*(col-1));
            for (int k=0; k<i; k++)
            {
                temp[j-1][index++] = arr[j][k];
            }
            for (int k=i+1; k<col; k++)
            {
                temp[j-1][index++] = arr[j][k];
            }
        }
        det += ((i%2==0)?1:-1)*arr[0][i]*determinant(temp, row-1, col-1);
    }
    printf("[");
    for (int i=0; i<row; i++)
    {
        printf("[");
        for (int j=0; j<col; j++)
        {
            printf("%d, ", arr[i][j]);
        }
        printf("], ");
    }
    printf("]\n");
    return det;
}


void main() {
    int** mat = (int **)malloc(sizeof(int*)*4);
    int index=1;
    for (int i=0; i<4; i++){
        mat[i] = (int*)malloc(sizeof(int)*4);
        for (int j=0; j<4; j++)
        {
            mat[i][j] = index++;
            if(i==j)
            {
                mat[i][j] = 1;
            }
        }
    }
    int a = determinant(mat, 4,4);
    printf("%d", a);
}