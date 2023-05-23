#include <stdio.h>

int main(){
    float celsius;
    printf("Input the temperature in celsius: ");
    scanf("%f", &celsius);
    printf("The temperature in fahrenheit is: %0.5f \n",(celsius*9/5)+32.0);
    return 0;
}
