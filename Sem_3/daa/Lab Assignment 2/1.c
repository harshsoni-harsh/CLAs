#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void linear_search(int** arr, int search, int input)
{
    int *a = *arr;
    clock_t start1, end1;
    int found=0;
    start1 = clock();
    for (int i=0; i<input; i++)
    {
        if(a[i]==search)
        {
            end1 = clock();
            printf("\nElement found at %d index\n", i);
            found = 1;
        }
    }
    if(found == 0)
    {
        end1 = clock();
        printf("\nElement not found\n");
    }
    printf("Time: %lfsec\n\n", ((double)(end1-start1))/CLOCKS_PER_SEC);
}
void binary_search(int** arr, int search, int input)
{
    int* a = *arr;
    clock_t start1, end1;
    start1 = clock();
    int low=0, high=input;
    int found=0;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(a[mid]==search)
        {
            end1 = clock();
            printf("Element found at %d index\n", mid);
            found = 1;
            break;
        }
        else if(search < a[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    if(found == 0)
    {
        end1 = clock();
        printf("Element not found\n");
    }
    printf("Time: %lfsec\n\n", ((double)(end1-start1))/CLOCKS_PER_SEC);
}

void main()
{
    int input, search;
    printf("Enter size of array: ");
    scanf("%d", &input);
    int *a = (int*)malloc(sizeof(int)*input);
    // printf("\nPrinting array...\n");
    for (int i=0; i<input; i++)
    {
        a[i] = i*i*0.23;
        // printf("%d\t", a[i]);
    }

    while(1)
    {
        printf("\n\nEnter element to search: ");
        scanf("%d", &search);
        printf("\nPerforming linear search");
        linear_search(&a, search, input);
        printf("Performing binary search\n");
        binary_search(&a, search, input);
    }
}