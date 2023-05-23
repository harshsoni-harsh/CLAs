#include <stdio.h>

int main(){
    int len=0;
    int max=100;
    char str[max], str2[max];
    printf("Enter the string: ");
    scanf("%s", str);
    for(int i=0; i<max, str[i]!='\0'; i++){
        len++;
    }
    for(int i=0; i<len; i++){
        str2[len-i-1]=str[i];
    }
    for(int i=0; i<len; i++){
        if(str[i]!=str2[i]){
            printf("\nString is not a palindrome\n");
            return 0;
        }
    }
    printf("\nString is a palindrome\n");
    return 0;
}