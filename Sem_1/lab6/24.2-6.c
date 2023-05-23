#include <stdio.h>

int main(){
    int x, y, a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    int gcd=1, lcm=1;
    a=x;
    b=y;
    int k=0;
    if(x>=y){
        k=x;
    }
    else{
        k=y;
    }
    for(int i=1; i<=k;i++){
        if(a!=0 && b!=0){
            if(a%i==0 && b%i==0){
                a/=i;
                b/=i;
                lcm*=i;
                gcd*=i;
            }
            else if(a%i==0){
                a/=i;
                lcm*=i;
            }
            else if(b%i==0){
                b/=i;
                lcm*=i;
            }
        }
    }
    printf("The LCM is %d\n", lcm);
    printf("GCD of numbers is %d\n", gcd);
    return 0;
}