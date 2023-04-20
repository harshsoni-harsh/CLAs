#include <stdio.h>
#include <string.h>
#include <ctype.h>

void count(char *a, int *vo, int *co);

void main()
{
    char b[100];
    printf("Enter the string: ");
    scanf("%s", b);
    int vowel = 0, consonant = 0;
    int *x=&vowel;
    int *y=&consonant;
    count(b, x,y);
    printf("No. of vowels=%d\nNo. of consonants=%d\n", vowel, consonant);
}

void count(char *a, int *vo, int *co)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if(65<=a[i]<=90 || 97<=a[i]<=122){
            tolower(a[i]);
            if (a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u')
                (*vo)++;
            else
                (*co)++;
        }
    }
}