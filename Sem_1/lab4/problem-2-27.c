#include <stdio.h>

int main(){
    int num1, num2;
    char c;
    printf("\n Enter the operator: ");
    scanf("%s",&c);
    printf("Enter the two numbers: ");
    scanf("%d%d", &num1,&num2);
    if(c=='+'){
        printf("\n The sum of the numbers is %d", num1+num2);
    }
    else if(c=='-'){
        printf("\n The difference of the numbers is %d", num1-num2);
    }
    else if(c=='*'){
        printf("\n The multiplication of the numbers is %d", num1*num2);
    }
    else if(c=='/'){
        printf("\n The division of the numbers is %0.2f", (float)num1/num2);
    }
    else if(c=='%'){
        printf("\n The modulo of the numbers is %d", num1%num2);
    }
    else{
        printf("\n Invalid input");
    }
    return 0;
}
