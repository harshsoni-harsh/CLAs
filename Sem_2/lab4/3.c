#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num;
    printf("Enter count of numbers: ");
    scanf("%d", &num);
    int *arr=(int*)calloc(num,sizeof(int));
    printf("Enter numbers & enter any character other than number to finish:\n");
    int counter=0;
    int d=0;
    while(counter<num)
    {
        scanf("%d", &d);
        arr[counter]=d;
        counter++;
    }
    int search, found=counter;
    printf("\nEnter any number to search: ");
    scanf("%d", &search);
    while(counter>0)
    {
        if(arr[counter--]==search)
        {
            break;
        }
    }
    if(counter)
    {
        printf("Found %d at index %d\n", search, num-counter-1);
        return;
    }
    printf("Not found\n");
    free(arr);
}