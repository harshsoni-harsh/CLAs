///////////////////////////
//subset with largest sum//
///////////////////////////

#include <stdio.h>

int maxSumSubArray(int* a)
{
    int maxSum=0;
    int curSum=0;
    int len;
    int max=a[0];
    for (len=0; a[len]!='\0' && a[len]<100000; len++)
    {
        if(a[len]>max)
        {
            max=a[len];
        }
    }
    if(max < 0)
    {
        return max;
    }
    for(int i=0; i<len; i++)
    {
        curSum+=a[i];
        if(curSum > maxSum)
        {
            maxSum = curSum;
        }
        if(curSum < 0)
        {
            curSum = 0;
        }
    }
    return maxSum;
}

void main()
{
    int array[] = {-1,-2,-4,-54,-2,-23};
    int demo[] = {4,43,-23,4,-25,43,1,5};
    printf("out: %d\n", maxSumSubArray(array));
    printf("out: %d\n", maxSumSubArray(demo));
}