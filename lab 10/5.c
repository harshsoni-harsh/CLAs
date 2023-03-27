#include <stdio.h>

int gcd(int a, int b);
int lcm(int a, int b);

void main(){
    int x,y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("GCD=%d\n", gcd(x,y));
    printf("LCM=%d\n", lcm(x,y));
}

int gcd(int a, int b){    
    if(b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}