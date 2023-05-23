#include <stdio.h>
#include <string.h>

int ispal(char *str, int start, int end);
int islen(char *str);
void main(){
    char x[100];
    printf("Enter the string: ");
    scanf("%s", x);
    if(islen(x))
    printf("It's a palindrome\n");
    else
    printf("It's not a palindrome\n");
}

int ispal(char *str, int start, int end){
    if(start==end)
    return 1;
    else if(str[start]!=str[end])
    return 0;
    else if(end<=start)
    ispal(str, start+1, end-1);
    return 1;
}
int islen(char *str){
    if(strlen(str)==0)
    return 0;
    return ispal(str, 0,strlen(str)-1);
}