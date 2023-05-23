#include <stdio.h>

int main()
{
    int p;
    float r,t;
    printf("Enter the principal balance: ");
    scanf("%d",&p);
    printf("\n Enter the rate of interest: ");
    scanf("%f",&r);
    printf("\n Enter the time period in years: ");
    scanf("%f",&t);
    float some=(1+r/100);
    float ci=p*(some);
    while (t>1)
    {
        ci=ci*some;
        t=t-1;
    }
    printf("Compound interest is: %f",ci);
    printf("\nSIMPLE INTEREST IS: %f\n",p+p*r*t/100);
    return 0;
}