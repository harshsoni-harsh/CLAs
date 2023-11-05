#include <stdio.h>
#include <stdlib.h>

int determinant(int **arr, int row, int col, int at_row, int at_col)
{
    if (row != col)
    {
        return 0; 
    }

    if (row == 2)
    {
        return (arr[at_row][at_col] * arr[at_row + 1][at_col + 1]) -
               (arr[at_row + 1][at_col] * arr[at_row][at_col + 1]);
    }
    
    int det = 0;
    for (int i = at_row; i < row; i++)
    {
        int sign = (i%2==0) ? 1 : -1; // Alternate signs for each term
        int cofactor = arr[i][at_col] * determinant(arr, row, col, i + 1, at_col + 1);
        det += sign * cofactor;
    }
    
    return det;
}


void main() {
    int** mat = (int **)malloc(sizeof(int*)*3);
    for (int i=0; i<3; i++){
        mat[i] = (int*)malloc(sizeof(int)*3);
        for (int j=0; j<3; j++)
        {
            mat[i][j] = 1;
        }
    }
    determinant(mat, 3,3,0,0);
}