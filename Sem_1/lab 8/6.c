#include <stdio.h>
#include <string.h>

void main(){
    char x1[100], x2[100];
    int len1, len2, count=0;
    printf("Enter the string1: ");
    scanf("%[^\n]s",x1);
    len1=strlen(x1);
    printf("\nEnter the string2: ");
    scanf("%s",x2);
    len2=strlen(x2);
    for(int i=0; i<len1; i++){
        if(x1[i]==x2[0]){
            int q=0, a=0;
            for(int j=0; j<len2; j++){
                if(x1[i+j]==x2[a]){
                    q++;
                    a++;
                }
            }
            if(q==len2)
            count++;
        }
    }
    printf("\n%s occurs %d times in %s\n", x2, count, x1);
}