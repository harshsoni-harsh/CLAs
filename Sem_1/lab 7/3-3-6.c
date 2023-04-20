#include <stdio.h>
#include <string.h>

int main(){
    int len=0, len2=0;
    int max=100;
    char str[max], str2[max];
    printf("Enter the string: ");
    scanf("%s", str);
    len=strlen(str);
    for(int i=0; i<len; i++){
        str2[len-i-1]=str[i];
    }
    if(strcmp(str2, str)){
        printf("\nString is not a palindrome\n");
        return 0;
    }
    printf("\nString is a palindrome\n");
    return 0;
}
