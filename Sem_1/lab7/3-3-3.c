#include <stdio.h>

int main(){
    int len=0, len2=0;
    int max=100;
    char str[max], str2[max];
    printf("Enter the string: ");
    scanf("%s", str);
    printf("Enter second string: ");
    scanf("%s", str2);
    for(int i=0; i<max, str[i]!='\0'; i++){
        len++;
    }
    for(int i=0; i<max, str2[i]!='\0'; i++){
        len2++;
    }
    if(len!=len2){
        printf("\nThe strings are not equal\n");
        return 0;
    }
    for(int i=0; i<len; i++){
        if(str[i]!=str2[i]){
            printf("\nThe strings are not equal\n");
            return 0;
        }
    }
    printf("\nString are equal\n");
    return 0;
}
