#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

void display(int *a, int len);
void analyse(int len, int x);
int insertion_sort(int *a, int len);
int merge_sort(int *a, int len);

void main()
{
    int arr[]={3425, 235, 99, 98, 45, 35, 4, 3, 2};
    // int arr[]={2,3,4,45,98,99,235,3425};
    int len=sizeof(arr)/sizeof(int);
    clock_t start, end;
    double runtime;
    start = clock();
    int x=insertion_sort(arr, len);
    end = clock();
    runtime = (double)(end-start)/CLOCKS_PER_SEC;
    analyse(len,x);
    // printf("Time Complexity: %0.2f n\n", (float)x/len);
    printf("Runtime: %lf\n\n", runtime);
}
void display(int *a, int len)
{
    printf("Printing array: ");
    for (int i=0; i<len; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n\n");
}
void analyse(int len, int x)
{
    printf("Time complexity: O(n^%0.2f)\n", log10(x)/log10(len));

}
int insertion_sort(int *a, int len)
{
    // display(a, len);
    int x=1;
    for(int j=1; j<len; j++)
    {
        int key=a[j];
        int i=j-1;
        x++;
        while(i>=0 && (key<a[i]))
        {
            int temp = a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            i--;
            x++;
        }
        // display(a, len);
    }
    return x;
}
int merge_sort(int *a, int len)
{
    
}
