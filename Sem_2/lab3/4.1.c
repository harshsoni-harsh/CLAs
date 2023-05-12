#include <stdio.h>

void toh(int disk, char source, char dest, char aux)
{
    if(disk==1)
    {
        printf("Move disk %d from %c to %c\n", disk, source, dest);
        return;
    }
    toh(disk-1, source, aux, dest);
    printf("Move disk %d from %c to %c\n", disk, source, dest);
    toh(disk - 1, aux, dest, source);
}
void main()
{
    char a='a',b='b',c='c';
    int disks;
    printf("Enter number of disks: ");
    scanf("%d", &disks);
    toh(disks, a,b,c);
}