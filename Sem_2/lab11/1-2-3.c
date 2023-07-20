#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int smallest = arr[i];
        int index = i;
        for (int j = i; i < len; i++)
        {
            if (smallest > arr[j])
            {
                index = j;
                smallest = arr[j];
            }
        }
        int temp = arr[i];
        arr[i] = smallest;
        arr[index] = temp;
    }
}
void insertion_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int num = *(arr + i);
        int index = i - 1;
        for (; num < *(arr + index); index--)
        {
            *(arr + index + 1) = *(arr + index);
        }
        *(arr + index + 1) = num;
    }
}
void merge(int *arr, int lo, int mid, int hi)
{
    int l1 = mid - lo + 1;
    int l2 = hi - mid;

    int *left = (int *)malloc(sizeof(int) * l1);
    int *right = (int *)malloc(sizeof(int) * l2);

    for (int i = 0; i < l1; i++)
    {
        left[i] = arr[lo+i];
        printf("left[%d]: %d\n", i,left[i]);
    }
    printf("\n");
    for (int i = 0; i < l2; i++)
    {
        right[i] = arr[mid+1+i];
        printf("right[%d]: %d\n", i,right[i]);
    }
    printf("\n");

    int t1 = 0, t2 = 0;
    for (int i = lo; i <= hi; i++)
    {
        if (t1 == l1)
        {
            arr[i] = right[t2++];
        }
        else if (t2 == l2)
        {
            arr[i] = left[t1++];
        }
        else if (right[t2] < left[t1])
        {
            arr[i] = right[t2++];
        }
        else
        {
            arr[i] = left[t1++];
        }
    }
    free(right);
    free(left);
}
void merge_sort(int *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int mid = (lo + hi) / 2;
        merge_sort(arr, lo, mid);
        merge_sort(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);
        for (int i = 0; i < 6; i++)
        {
            printf("%d  ", *(arr + i));
        }
        printf("\n");
    }
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
    merge_sort(arr, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        printf("%d  ", *(arr + i));
    }
    printf("\n");
}
