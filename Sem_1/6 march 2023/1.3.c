#include <stdio.h>
#include <string.h>

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float modulo(float a, float b);

int main(){
    float x, y;
    float calc;
    char o[20];
    printf("Enter two numbers: ");
    scanf("%f %f", &x, &y);
    printf("What arithmetic operation do u want to perform, type in lowercase?\n");
    scanf("%s", o);
    char op[3];
    strcat(op,&o[0]);
    strcat(op,&o[1]);
    op[2]='\0';
    if(strcmp(op,"ad")==0){
    calc=add(x,y);}
    else if(strcmp(op,"su")==0){
    calc=subtract(x,y);}
    else if(strcmp(op,"mu")==0){
    calc=multiply(x,y);}
    else if(strcmp(op,"di")==0){
    calc=divide(x,y);}
    else if(strcmp(op,"mo")==0){
    calc=modulo(x,y);}
    else{
        printf("Invalid input\n");
        // return 0;
    }
    printf("\n%f\n", calc);
    return 0;
}

float add(float a, float b){
    return a+b;
}
float subtract(float a, float b){
    return a-b;
}
float multiply(float a, float b){
    return a*b;
}
float divide(float a, float b){
    return a/b;
}
float modulo(float a, float b){
    return (int)a%(int)b;
}