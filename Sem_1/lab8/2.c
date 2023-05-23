#include <stdio.h>
#include <string.h>

void main(){
    char x[100],q;
    int vowel=0, cons=0;
    printf("Enter the string: ");
    scanf("%[^\n]s",x);
    for(int i=0; i<strlen(x); i++){
        q=x[i];
        if(q=='A' || q=='E' || q=='I' || q=='O' || q=='U')
        vowel++;
        else if(q=='a' || q=='e' || q=='i' || q=='o' || q=='u')
        vowel++;
        else if(q==' ')
        continue;
        else
        cons++;
    }
    printf("There are %d vowels\n", vowel);
    printf("There are %d consonants\n", cons);
}