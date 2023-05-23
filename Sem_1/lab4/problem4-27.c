#include <stdio.h>

int main(){
    int num;
    printf("Input the number: ");
    scanf("%d", &num);
    int sum=0;
    while(num!=0){
    sum+=num%10;
    num/=10;
   }
    printf("%d \n", sum);
    return 0;
}
