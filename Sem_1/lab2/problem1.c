#include <stdio.h>

int main()
{
    int a,b;
    float c,d;
    printf("Enter the integers: ");
    scanf("%d %d",&a,&b);
    printf("\nThe sum of the integers is: %d\n",a+b);
    printf("Enter the floating points: ");
    scanf("%f %f",&c,&d);
    printf("\nThe sum of the floating point is: %f\n",c+d);
    return 0;
}