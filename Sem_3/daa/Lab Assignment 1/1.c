#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubble_sort(int* a[], int len)
{
    int *arr = *a;
    int temp;
    int flag=1;
    while(flag)
    {
        flag=0;
        for (int j=0; j<len; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag=1;
            }
        }
    }
}
void selection_sort(int* a[], int len)
{
    int *arr = *a;
    int flag=1;
    for (int i=0; i<len; i++)
    {
        flag=0;
        int k=len-i-1;
        int max = arr[len-i-1];
        for (int j=0; j<len-i; j++)
        {
            if(arr[j] > max)
            {
                max = arr[j];
                k=j;
                flag=1;
            }
        }
        max = arr[len-i-1];
        arr[len-i-1] = arr[k];
        arr[k] = max;
    }
}
void merge(int* array[], int low, int mid, int high)
{
    int *arr = *array;
    int a[mid-low+1];
    int b[high-mid];
    for (int i=low; i<mid+1; i++)
    {
        a[i-low] = arr[i];
    }
    for (int i=mid+1; i<=high; i++)
    {
        b[i-mid-1] = arr[i];
    }
    int index1 = 0, index2 = 0, index = low;
    while(index1<(mid-low+1) && index2<(high-mid))
    {
        if((a[index1] <= b[index2]))
        {
            arr[index++] = a[index1++];
        }
        else
        {
            arr[index++] = b[index2++];
        }
    }
    while(index1 < mid-low+1)
    {
        arr[index++] = a[index1++];
    }
    while(index2<(high-mid))
    {
        arr[index++] = b[index2++];
    }
}
void merge_sort(int* arr[], int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}
void merge_sorts(int* a[], int len)
{
    int low = 0;
    merge_sort(a, low, len-1);
}
void compare(int* arr[], int len, void sort(int**, int))
{
    int *a = *arr;
    clock_t start1, start2, start3, end1, end2, end3;

    start2 = clock();
    sort(arr, len);
    end2 = clock();
    
    for (int i=0; i<len/2; i++)
    {
        int temp = a[i];
        a[i] = a[len-1-i];
        a[len-1-i] = temp;
    }

    start1 = clock();
    sort(arr, len);
    end1 = clock();

    for (int i=0; i<len/4; i++)
    {
        int temp = a[i];
        a[i] = a[len/4+i];
        a[len-1-i] = temp;
    }

    start3 = clock();
    sort(arr, len);
    end3 = clock();
    
    printf("Time for sorted case: %lfsec\n", ((double)(end2-start2))/CLOCKS_PER_SEC);
    printf("Time for half sorted case: %lfsec\n", ((double)(end3-start3))/CLOCKS_PER_SEC);
    printf("Time for unsorted case: %lfsec\n", ((double)(end1-start1))/CLOCKS_PER_SEC);
}


void main()
{
    int input;
    printf("Enter size of array: ");
    scanf("%d", &input);
    int *a = (int*)malloc(sizeof(int)*input);
    for (int i=0; i<input; i++)
    {
        a[i] = i;
    }
    printf("\n\nTesting with merge sort algorithm\n");
    compare(&a, input, merge_sorts);
    printf("\n\nTesting with selection sort algorithm\n");
    compare(&a, input, selection_sort);
    printf("\n\nTesting with bubble sort algorithm\n");
    compare(&a, input, bubble_sort);
}