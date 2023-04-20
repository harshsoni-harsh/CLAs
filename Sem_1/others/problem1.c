#include <stdio.h>
#include <math.h>

void main(){
    int price=1550000;
    int paid=85000;
    int interest=16;
    int months=60;
    price-=paid;
    int si=(price*interest*months/12/100+price)/60;
    //printf("Equated monthly installments he has to pay is Rs %0.2f \n",(price*interest*pow(1.16,months)/(pow(1.16,months)-1))/100);
    printf("Equated monthly installments from SI is Rs %d \n",si);
    float some=(1+interest/100);
    float ci=price*some;
    int t=months/12;
    while (t>1)
    {
        ci=ci*some;
        t=t-1;
    }
    printf("Equated monthly installments from CI is Rs %0.2f \n",ci/60);
    return 0;
}
