#include <stdio.h>
#include <string.h>
#include <ctype.h>

void rev(char *str);

void main(){
    char st[100];
    printf("Enter the string: ");
    scanf("%[^\n]s", st);
    printf("Original string is: %s\n", st);
    rev(st);
    printf("Reversed string is: %s\n", st);
}

void rev(char *str){
    int len=strlen(str);
    char r[len];
    int i=0;
    for(int k=0; k<len; k++){
        if(isspace(str[k])){
            r[k]=str[k];
            continue;
        }
        if(i%2==0){
            r[k]=tolower(str[k]);
        }
        else if(i%2==1){
            r[k]=toupper(str[k]);
        }
        i++;
    }   
    r[len]=0;
    strcpy(str,r);
}