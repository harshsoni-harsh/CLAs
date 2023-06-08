#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num;
    printf("Enter count of numbers: ");
    scanf("%d", &num);
    int *arr=(int*)calloc(num,sizeof(int));
    printf("Enter numbers:\n");
    int counter=0;
    int d=0;
    while(counter<num)
    {
        scanf("%d", &arr[counter++]);
    }
    int search, found=-1;
    printf("\nEnter any number to search: ");
    scanf("%d", &search);
    while(found<counter)
    {
        if(arr[++found]==search)
        {
            free(arr);
            printf("Found %d at index %d\n", search, found);
            return;
        }
    }
    free(arr);
    printf("Not found\n");
}