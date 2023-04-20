#include <stdio.h>
int r1, r2, c1, c2, inpu=0;
int m1[1][1];
int m2[1][1];
long int m3[1][1];
long int m4[1][1];
void scan1(int r, int c){
    printf("\nWrite the matrix 1 with dimensions %d x %d\n", r, c);
    for(int i=0; i<r; i++){
        m1[i]={0};
        /* printf("\nEnter the inputs for column %d of matrix 1 \n", i); */
        for(int k=0; k<c; k++){
            scanf("%d",&inpu);
            m1[i][k]=inpu;
        }
    }
    for(int i=0; i<r; i++){
        /* printf("\nEnter the inputs for column %d of matrix 1 \n", i); */
        for(int k=0; k<c; k++){
            m1[i][k]=inpu;
            printf("%d ",inpu);
        }
    }
}
void scan2(int r, int c){
    printf("\nWrite the matrix 1 with dimensions %d x %d\n", r, c);
    for(int i=0; i<r; i++){
        /* printf("\nEnter the inputs for column %d of matrix 1 \n", i); */
        for(int k=0; k<c; k++){
            scanf("%d",&inpu);
            m2[i][k]=inpu;
        }
    }
    for(int i=0; i<r; i++){
        /* printf("\nEnter the inputs for column %d of matrix 1 \n", i); */
        for(int k=0; k<c; k++){
            m2[i][k]=inpu;
            printf("%d",inpu);
        }
    }
}
void multiply(int a, int b, int c){
    printf("\nThe multiplication of matrices are as follows: \n");
    for(int i=0; i<a; i++){
        for(int k=0; k<c; k++){
            m3[i][k]=0;
            for(int j=0; j<b; j++){
                m3[i][k]+=m1[i][j]*m2[j][k];
            }
        }
    }
    for(int i=0; i<a; i++){
        for(int k=0; k<c; k++){
            printf("%ld ",m3[i][k]);
        }
        printf("\n");
    }
}
void add(int a , int b){
    printf("\nThe addition of matrices is as follows: \n");
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            m4[i][j]=m1[i][j]+m2[i][j];
            printf("%ld",m4[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<a; i++){
        for(int k=0; k<b; k++){
            printf("%ld ",m4[i][k]);
        }
        printf("\n");
    }
}
int main(){
    printf("Enter the row and column of matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the row and column of matrix 2: ");
    scanf("%d %d", &r2, &c2);
    int m1[r1][c1];
    int m2[r2][c2];
    long int m3[r1][c2];
    long int m4[r1][c1];    
    if(r1==r2 && c1==c2 && r2==c1){
        scan1(r1, c1);
        scan2(r2, c2);
        add(r1, c1);
        multiply(r1, c1, c2);

    }
    else if(r1==r2 && c1==c2){
        scan1(r1, c1);
        scan2(r2, c2);
        add(r1, c1);
    }
    else if(r2!=c1){
        printf("Row of 2 and column of 1 should be same for matrix multiplication");
        printf("\nOr\nThe rows and columns should have the same length for matrix addition\n");
    }
    else{
        scan1(r1, c1);
        scan2(r2, c2);
        multiply(r1, c1, c2);
    }
    return 0;
}
