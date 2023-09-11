#include <stdio.h>
#include <time.h>

void printarr(int arr[], int index, int len)
{
    if(index >= len)
    {
        printf("\n");
        return;
    }
    printf("%d  ", arr[index]);
    printarr(arr, index+1, len);
}
void main()
{
    int len;
    printf("Enter length of array: ");
    scanf("%d", &len);
    printf("\nEnter array: ");
    int arr[len];
    for (int i=0; i<len; i++)
    {
        scanf("%d", &arr[i]);
    }
    clock_t start, end, start2, end2;
    int index = 0;
    start = clock();
    printarr(arr, index, len);
    end = clock();
    start2 = clock();
    for(int i=0; i<len; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    end2 = clock();
    printf("\n%f more time is taken by recursion in comparison to iterations\n\n", ((double)((end-start)-(end2-start2))/CLOCKS_PER_SEC));
}