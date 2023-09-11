//bubble sort

#include <stdio.h>
#include <time.h>

void bubble_sort(int arr[], int len)
{
    /*
    int temp;
    for (int i=0; i<len; i++)
    {
        for (int j=0; j<i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    */
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

void main()
{
    int a[1000000];
    int input;
    printf("Enter size of array: ");
    scanf("%d", &input);
    for (int i=0; i<input; i++)
    {
        a[i] = i;
    }
    clock_t start1, start2, start3, end1, end2, end3;

    start2 = clock();
    bubble_sort(a, input);
    end2 = clock();
    
    for (int i=0; i<input/2; i++)
    {
        int temp = a[i];
        a[i] = a[input-1-i];
        a[input-1-i] = temp;
    }

    start1 = clock();
    bubble_sort(a, input);
    end1 = clock();

    for (int i=0; i<input/4; i++)
    {
        int temp = a[i];
        a[i] = a[input/4+i];
        a[input-1-i] = temp;
    }

    start3 = clock();
    bubble_sort(a, input);
    end3 = clock();
    
    printf("Time for best case: %lfsec\n", ((double)(end2-start2))/CLOCKS_PER_SEC);
    printf("Time for average case: %lfsec\n", ((double)(end3-start3))/CLOCKS_PER_SEC);
    printf("Time for worst case: %lfsec\n", ((double)(end1-start1))/CLOCKS_PER_SEC);
}