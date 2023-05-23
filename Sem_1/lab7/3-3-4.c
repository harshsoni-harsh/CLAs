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
    printf("%d %d\n", len, len2);
    char str3[len+len2-1];
    int i=0;
    for(int num=0; i<len, num<len; i++){
        str3[i]=str[num];
        num++;
    }
    for(int num2=0; num2<len2; i++){
        str3[i]=str2[num2];
        num2++;
    }
    str3[i+1]='\0';
    printf("\nConcatenated string is %s\n", str3);
    return 0;
}