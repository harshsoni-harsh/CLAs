#include <stdio.h>
#include <string.h>

void main(){
    char x1[100], x2[100], x3[100];
    int num, len1, len2, q=0;
    printf("Enter the string1: ");
    gets(x1);
    len1=strlen(x1);
    printf("Enter the string2: ");
    gets(x2);
    len2=strlen(x2);
    printf("Enter the position to concatenate: ");
    scanf("%d", &num);
    for(int i=0; i<num && i<len1; i++){
        x3[q]=x1[i];
        q++;
    }
    for(int j=0; j<len2; j++){
        x3[q]=x2[j];
        q++;
    }
    x3[q]=*" ";
    q++;
    for(int k=num; k<len1; k++){
        x3[q]=x1[k];
        q++;
    }
    x3[q]=0;
    printf("%s\n", x3);
}