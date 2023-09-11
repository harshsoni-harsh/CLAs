#include <stdio.h>
#include <time.h>

long long fact(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    return n*fact(n-1);
}
void main()
{
    clock_t start, end, start2,end2;
    
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    start = clock();
    long long fac = fact(n);
    end = clock();
    printf("\n%d! =  %lld\n", n, fac);

    start2 = clock();
    long long curr = 1;
    int times = 1;
    int temp;
    while(times <= n)
    {
        curr *= times;
        times += 1;
    }
    end2 = clock();
    printf("\n%d! =  %lld\n", n, curr);
    printf("\n%f more time is taken by recursion in comparison to iterations\n\n", ((double)((end-start)-(end2-start2))/CLOCKS_PER_SEC));
}