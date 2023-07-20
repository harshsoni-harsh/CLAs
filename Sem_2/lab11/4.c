#include <stdio.h>
#include <stdlib.h>

void insertion_sort_desc(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int num = *(arr + i);
        int index = i-1;
        for (; index>=0 && num > *(arr + index); index--)
        {
            *(arr + index + 1) = *(arr+index);
        }
        *(arr + index + 1) = num;
    }
}

int binary_search(int *arr, int len, int search)
{
    int lo = 0, hi = len;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (search == arr[mid])
        {
            return mid;
        }
        else if (search < arr[mid])
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return -1;
}

void main()
{
    int len;
    printf("Enter number of elements: ");
    scanf("%d", &len);
    int *arr = (int *)malloc(len * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < len; i++)
    {
        int t;
        scanf("%d", &t);
        *(arr + i) = t;
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d  ", *(arr + i));
    }
    printf("\n");

    int search = 0;
    printf("Enter element to search: ");
    scanf("%d", &search);

    int found = binary_search(arr, len, search);
    if (found == -1)
    {
        printf("Not found\n");
        insertion_sort_desc(arr, len);
        for (int i = 0; i < len; i++)
        {
            printf("%d  ", *(arr + i));
        }
        printf("\n");
    }
    else
    {
        printf("Found at index: %d\n", found);
    }
}