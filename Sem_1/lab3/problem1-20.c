#include <stdio.h>
#include <math.h>

int main(){
    int price=1550000;
    int paid=85000;
    int interest=16;
    int months=60;
    price-=paid;
    int si=(price*interest*months/(12*100)+price)/60;

    printf("Equated monthly installments from SI is Rs %d \n",si);

    float ci = (price * (1 + pow((interest / (100.0)), 60.0)));
    printf("Equated monthly installments from CI is Rs %0.2f \n",ci/60.0);
    return 0;
}
