#include <stdio.h>
#include <time.h>

int gcd(int a, int b)
{
    if(a==b)
    {
        return a;
    }
    else if(a>b)
    {
        if(a%b==0)
        {
            return b;
        }
        return gcd((b), a%b);
    }
    else
    {
        if(b%a==0)
        {
            return a;
        }
        return gcd((a), b%a);
    }
}
void main()
{
    clock_t start, end, start2,end2;
    
    int a,b;
    printf("Enter a larger, then a smaller number: ");
    scanf("%d %d", &a, &b);
    start = clock();
    int g = gcd(a,b);
    end = clock();
    printf("\nlcm(%d, %d) =  %d\n", a,b, a*b/g);

    g = a;
    int temp;
    int a1 = a;
    int b1 = b;
    start2 = clock();
    while(1)
    {
        if(a==b)
        {
            g = a;
            break;
        }
        else
        {
            if(a%b==0)
            {
                g = b;
                break;
            }
            temp = a%b;
            a = b;
            b = temp;
        }
    }
    end2 = clock();
    printf("\nlcm(%d, %d) =  %d\n", a1,b1, a1*b1/g);
    printf("\n%f more time is taken by recursion in comparison to iterations\n\n", ((double)((end-start)-(end2-start2))/CLOCKS_PER_SEC));
}