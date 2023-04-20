#include <stdio.h>
#include <string.h>

void main(){
    char str[30]="subtraction";
    char a[1];
    char s[3];
    a[1]=str[0];
    strcat(s, a);
    a[1]=str[1];
    strcat(s, a);
    s[3]=0;
    // printf("%d\n", strcmp(a,s));
}