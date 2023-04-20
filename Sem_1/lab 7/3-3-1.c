#include <stdio.h>

void main(){
    int len=0;
    int max=100;
    char str[max];
    printf("Enter the string: ");
    scanf("%s", str);
    for(int i=0; i<max, str[i]!='\0'; i++){
        len++;
    }
    printf("\nThe length of string is %d\n", len);
}