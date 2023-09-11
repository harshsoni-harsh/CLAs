//selection sort

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
    clock_t start1, start2, start3, end1, end2, end3;

    // printf("\nBefore sort: ");
    // for (int i=0; i<input; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    printf("Best case:\n");
    for (int i=0; i<1; i++)
    {

        start1 = clock();
        selection_sort(&a, input);
        end1 = clock();
        start2 = clock();
        selection_sort(&a, input);
        end2 = clock();
        start3 = clock();
        selection_sort(&a, input);
        end3 = clock();

        printf("%0.2f_ms\t", ((double)((end1-start1)*1000))/CLOCKS_PER_SEC);
        printf("%0.2f_ms\t", ((double)((end2-start2)*1000))/CLOCKS_PER_SEC);
        printf("%0.2f_ms\t", ((double)((end3-start3)*1000))/CLOCKS_PER_SEC);
        printf("\n");
    }

    printf("Average case:\n");
    for (int i=0; i<1; i++)
    {
        for (int i=0; i<input/2; i++)
        {
            int temp = a[i];
            a[i] = a[input-1-i];
            a[input-1-i] = temp;
        }
        start1 = clock();
        selection_sort(&a, input);
        end1 = clock();   
        for (int i=0; i<input/2; i++)
        {
            int temp = a[i];
            a[i] = a[input-1-i];
            a[input-1-i] = temp;
        }
        start2 = clock();
        selection_sort(&a, input);
        end2 = clock();    
        for (int i=0; i<input/2; i++)
        {
            int temp = a[i];
            a[i] = a[input-1-i];
            a[input-1-i] = temp;
        }
        start3 = clock();
        selection_sort(&a, input);
        end3 = clock();

        printf("%0.2f_ms\t", ((double)((end1-start1)*1000))/CLOCKS_PER_SEC);
        printf("%0.2f_ms\t", ((double)((end2-start2)*1000))/CLOCKS_PER_SEC);
        printf("%0.2f_ms\t", ((double)((end3-start3)*1000))/CLOCKS_PER_SEC);
        printf("\n");
    }

    for (int i=0; i<10; i++)
    {

        start1 = clock();
        selection_sort(&a, input);
        end1 = clock();
        start2 = clock();
        selection_sort(&a, input);
        end2 = clock();
        start3 = clock();
        selection_sort(&a, input);
        end3 = clock();

        printf("%0.2f_ms\t", ((double)((end1-start1)*1000))/CLOCKS_PER_SEC);
        printf("%0.2f_ms\t", ((double)((end2-start2)*1000))/CLOCKS_PER_SEC);
        printf("%0.2f_ms\t", ((double)((end3-start3)*1000))/CLOCKS_PER_SEC);
        printf("\n");
    }
    // // printf("\nAfter sort: ");
    // // for (int i=0; i<input; i++)
    // // {
    // //     printf("%d ", a[i]);
    // // }
    // // printf("\n");


    // printf("\nBefore sort: ");
    // for (int i=0; i<input; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");

    // start1 = clock();
    // selection_sort(&a, input);
    // end1 = clock();

    // // printf("\nAfter sort: ");
    // // for (int i=0; i<input; i++)
    // // {
    // //     printf("%d ", a[i]);
    // // }
    // // printf("\n");

    // for (int i=0; i<input/4; i++)
    // {
    //     int temp = a[i];
    //     a[i] = a[input/2-1-i];
    //     a[input/2-1-i] = temp;
    // }

    // printf("\nBefore sort: ");
    

    // start3 = clock();
    // selection_sort(&a, input);
    // end3 = clock();

    // // printf("\nAfter sort: ");
    // // for (int i=0; i<input; i++)
    // // {
    // //     printf("%d ", a[i]);
    // // }
    // // printf("\n");
        
    // printf("Time for best case: %0.2f milliseconds\n", ((double)((end2-start2)*1000))/CLOCKS_PER_SEC);
    // printf("Time for average case: %0.2f milliseconds\n", ((double)((end3-start3)*1000))/CLOCKS_PER_SEC);
    // printf("Time for worst case: %0.2f milliseconds\n", ((double)((end1-start1)*1000))/CLOCKS_PER_SEC);
}