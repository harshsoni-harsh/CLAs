#include <stdio.h>

int main(){
    int salary, hra, da;
    printf("input the salary: ");
    scanf("%d", &salary);
    if(salary<=10000){
        hra=20;
        da=80;
    }
    else if(10001<=salary<=20000){
        hra=25;
        da=90;
    }
    else if(salary>=20001){
        hra=30;
        da=95;
    }
    printf("Gross salary is %d \n", salary+(salary*(da+hra)/100));
    return 0;
}
