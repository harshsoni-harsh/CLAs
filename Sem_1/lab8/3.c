#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(){
    char x[100], y[100];
    printf("Enter the string: ");
    scanf("%[^\n]s", x);
    for(int i=0; i<strlen(x); i++){
        if(i%2==0){
            y[i]=tolower(x[i]);
        }
        else{
            y[i]=toupper(x[i]);
        }
    }
    y[strlen(x)]=0;
    printf("%s\n", y);
}