#include <stdio.h>

int main()
{
    int employee;
    double daily, hra, basic;
    printf("Employee id: ");
    scanf("%d",&employee);
    printf("\nBasic Salary: ");
    scanf("%lf",&basic);
    printf("\nDaily Allowance: ");
    scanf("%lf",&daily);
    printf("\nHRA: ");
    scanf("%lf",&hra);
    printf("\n The gross salary is: %lf \n",basic + daily*basic/100 + hra*basic/100);
    return 0;
}