#include <stdio.h>

int main(){
    int x,y,a;
    printf("Enter the marks of Ram: ");
    scanf("%d",&x);
    printf("\n Enter the marks of Sam: ");
    scanf("%d",&y);
    a=y;
    y=x;
    x=a;
    printf("Actual marks of Ram is %d \n",x);
    printf("Actual marks of Sam is %d \n",y);
    return 0;
}
