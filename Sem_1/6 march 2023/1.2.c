#include <stdio.h>

void isprime(int n, int m);

void main(){
    int x, y;
    printf("Enter the range: ");
    scanf("%d %d", &x, &y);
    isprime(x, y);
}

void isprime(int n, int m){
    int a=0;
    for(int j=n; j<m; j++){
        int factor=0;
        for(int i=1; i<j; i++){
            if(j%i==0){
                factor+=1;
            }
        }
        if(factor==1){
            if(a%13==0){
                printf("\n");
            }
            a++;
            printf("%d\t", j);
        }
    }
    printf("\n");
}