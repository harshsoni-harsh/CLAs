#include <stdio.h>
#include <string.h>

void rev(char *str);

void main(){
    char st[100];
    printf("Enter the string: ");
    scanf("%[^\n]s", st);
    rev(st);
    printf("Reversed string is: %s\n", st);
}

void rev(char *str){
    int len=strlen(str);
    char r[len];
    for(int i=0; i<len; i++){
        r[i]=str[len-i-1];
    }
    r[len]=0;
    strcpy(str,r);
}