#include <stdio.h>

int main(){
    int num, j=1;
    printf("Enter the size of triangle pattern: ");
    scanf("%d", &num);
    printf("\nPattern is as follows: \n");
    for(int i=0; i<num; i++){
        for(int j=num; j>i; j--){
            printf(" ");
        }
        for(j=1; j<=i; j++){
            printf("%d", j);
        }
        for(; j>0; j--){
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}