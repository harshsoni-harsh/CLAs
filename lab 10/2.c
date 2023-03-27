#include <stdio.h>
#include <string.h>

void main(){
    FILE *fp, *fp1;
    fp=fopen("file.txt", "r");
    fp1=fopen("file1.txt", "w");
    char ch[100];
    while(fscanf(fp, "%s", ch)==1){
        char h[100];
        int len=strlen(ch);
        for(int i=0; i<len; i++){
            h[i]=ch[len-i-1];
        }
        fprintf(fp1, "%s \n", h);
    }
    fclose(fp);
    fclose(fp1);
}