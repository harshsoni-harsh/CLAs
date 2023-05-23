#include <stdio.h>

int main(){
    int r1, r2, c1, c2, input;
    printf("Write the dimensions of matrix 1: \n");
    scanf("%d %d", &r1, &c1);
    printf("\nWrite the dimensions of matrix 2: \n");
    scanf("%d %d", &r2, &c2);
    int m1[r1][c1];
    printf("\nEnter the matrix: \n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            scanf("%d", &input);
            m1[i][j]=input;
        }
    }
    int m2[r2][c2];
    printf("\nEnter the matrix: \n");
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            scanf("%d", &input);
            m2[i][j]=input;
        }
    }
    if(r1==r2 && c1==c2 && r2==c1){
        //addition
        printf("\nThe addition of matrices is as follows: \n");
        int m3[r1][c1];
        for(int i=0; i<r1; i++){
            for(int j=0; j<c1; j++){
                m3[i][j]=m1[i][j]+m2[i][j];
                printf("%d ", m1[i][j]+m2[i][j]);
            }
            printf("\n");
        }
        //multiplication
        printf("\nThe multiplication of matrices is as follows\n");
        int m4[r1][c2];
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                m4[i][j]=0;
                for(int k=0; k<c1; k++){
                    m4[i][j]+=m1[i][k]*m2[k][j];
                }
                printf("%d ", m4[i][j]);
            }
            printf("\n");
        }
    }
    else if(r1==r2 && c1==c2){
        //addition
        printf("\nThe addition of matrices is as follows: \n");
        int m3[r1][c1];
        for(int i=0; i<r1; i++){
            for(int j=0; j<c1; j++){
                m3[i][j]=m1[i][j]+m2[i][j];
                printf("%d ", m1[i][j]+m2[i][j]);
            }
            printf("\n");
        }
    }
    else if(r2==c1){
        //multiplication
        printf("\nThe multiplication of matrices is as follows\n");
        int m4[r1][c2];
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                m4[i][j]=0;
                for(int k=0; k<c1; k++){
                    m4[i][j]+=m1[i][k]*m2[k][j];
                }
                printf("%d ", m4[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("\nEither column of matrix 1 should be the size of row of matrix 2 ::  For matrix multiplication\n");
        printf("Or");
        printf("\nColumns or rows of both matrices should match :: For matrix addition\n");
    }
    return 0;
}