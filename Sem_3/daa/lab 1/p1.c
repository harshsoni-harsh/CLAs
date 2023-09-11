#include <stdio.h>
#include <time.h>

int fibonacci(int n)
{
    if(n<2)
    {
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
void main()
{
    clock_t start, end, start2,end2;
    
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    start = clock();
    int fib = fibonacci(n-1);
    end = clock();
    printf("\n%dth fibonacci number is %d\n", n, fib);

    start2 = clock();
    int prev = 0;
    int curr = 1;
    int times = 0;
    int temp;
    while(times < n-1)
    {
        temp = prev;
        prev = curr;
        curr += temp;
        times += 1;
    }
    end2 = clock();
    printf("\n%dth fibonacci number is %d\n", n, prev);
    printf("\n%f more time is taken by recursion in comparison to iterations\n\n", ((double)((end-start)-(end2-start2))/CLOCKS_PER_SEC));
}