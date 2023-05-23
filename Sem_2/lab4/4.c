#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num;
    printf("Enter count of numbers: ");
    scanf("%d", &num);
    int *arr=(int*)calloc(num,sizeof(int));
    printf("Enter %d numbers:\n", num);
    int counter=0;
    int d=0;
    while(counter<num)
    {
        scanf("%d", &d);
        arr[counter]=d;
        counter++;
    }
    int search;
    printf("\nEnter any number to search: ");
    scanf("%d", &search);
    
    int mid=0, low=0, high=counter, found=0;
    while(low<=high)
    {
        mid=low + (high-low)/2;
        if(search==arr[mid])
        {
            found=1;   
            break;
        }
        else if(search < arr[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    if(found)
    {
        printf("Found %d at index %d\n", search, mid);
        return;
    }
    printf("Not found\n");
    free(arr);
}