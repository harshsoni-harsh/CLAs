#include <stdio.h>

int main(){
    char str[100];
    printf("Enter the string: ");
    scanf("%s",str);
    printf("\nPrinting string in ascii values\n");
    for(int i=0; i<100, str[i]!='\0'; i++){
        printf("%d ", str[i]);
    }
    printf("\n");
    return 0;
}