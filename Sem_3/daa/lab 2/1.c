//linear search

#include <stdio.h>
#include <time.h>

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
    int worst_case=input-1;
    int best_case=1;
    int average_case=input/2;
    clock_t start1, start2, start3, end1, end2, end3;
    start1 = clock();
    start2 = clock();
    start3 = clock();
    for (int i=0; i<input; i++)
    {
        if(a[i]==worst_case)
        {
            end1 = clock();
        }
        else if(a[i]==best_case)
        {
            end2 = clock();
        }
        else if(a[i]==average_case)
        {
            end3 = clock();
        }
    }
    printf("Time for best case: %lfsec\n", ((double)(end2-start2))/CLOCKS_PER_SEC);
    printf("Time for average case: %lfsec\n", ((double)(end3-start3))/CLOCKS_PER_SEC);
    printf("Time for worst case: %lfsec\n", ((double)(end1-start1))/CLOCKS_PER_SEC);
}