#include <stdio.h>
#include <string.h>

void rev(char *str);

void main(){
    char a[50];
    printf("Input the string: ");
    scanf("%s", a);
    char *p=a;
    rev(p);
    printf("Reversed string is: %s\n", p);
}

void rev(char *str){
    char x[50];
    for(int i=strlen(str)-1, j=0; j<strlen(str); j++, i--){
        x[j]=str[i];
    }
    strcpy(str,x);
}