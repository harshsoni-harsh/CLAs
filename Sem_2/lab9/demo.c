#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char a[50] = "wednesday";
    char b[50] = "winter";
    char c[50] = "wednesday
    printf("\nDat: %d %d %d\n", strcmp(a,b), strcmp(b,a), strcmp(a,c));
}