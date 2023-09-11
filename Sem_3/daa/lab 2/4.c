//merge sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void main()
{
    int input, low=0;
    printf("Enter size of array: ");
    scanf("%d", &input);
    int *a = (int*)malloc(sizeof(int)*input);
    for (int i=0; i<input; i++)
    {
        a[i] = i;
    }
    clock_t start1, start2, start3, end1, end2, end3;

   // merge(&a, low, input/2, input - 1);

    start2 = clock();
    merge_sort(&a, low, input - 1);
    end2 = clock();
    
    for (int i=0; i<input; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    // for (int i=0; i<input/2; i++)
    // {
    //     int temp = a[i];
    //     a[i] = a[input-1-i];
    //     a[input-1-i] = temp;
    // }

    // start1 = clock();
    // merge_sort(&a, low, input-1);
    // end1 = clock();

    // for (int i=0; i<input; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    

    // for (int i=0; i<input/4; i++)
    // {
    //     int temp = a[i];
    //     a[i] = a[input/4+i];
    //     a[input-1-i] = temp;
    // }

    // start3 = clock();
    // merge_sort(&a, low, input - 1);
    // end3 = clock();

    // for (int i=0; i<input; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    
    // printf("Time for best case: %lfsec\n", ((double)(end2-start2))/CLOCKS_PER_SEC);
    // printf("Time for average case: %lfsec\n", ((double)(end3-start3))/CLOCKS_PER_SEC);
    // printf("Time for worst case: %lfsec\n", ((double)(end1-start1))/CLOCKS_PER_SEC);
}