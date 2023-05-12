#include <stdio.h>
#include "stacks.h"
#include <time.h>

stack maint, target, buffer, buffer_2;

int n, d;
clock_t start_time, end_time;
void displayto();

void Sleep(int time)
{
    clock_t start, end;
    double run;
    start=clock();
    while(((end-start)/CLOCKS_PER_SEC)<time/1000)
    {
        end=clock();
    }
}

void toh(stack *mant, stack *targt, stack *buffr, stack *buffr_2, int disk)
{
    if(disk <= 1)
    {
        push(targt, pop(mant));
        displayto(); 
        end_time = clock();
        printf("TIME = %lf", (double)(end_time - start_time) / CLOCKS_PER_SEC);
        printf("\033[u");
        Sleep(d);
        return;
    }
    Sleep(20);
    toh(mant, buffr, buffr_2, targt, disk - 2);
    toh(mant, buffr, targt, disk - 2);
    push(targt, pop(mant));
    toh(buffr, targt, mant, disk - 2);
    return;
}

/*
    void toh(stack *a, stack *b, stack *c, stack *d, int height)
    {
        if(height<=1)
        {
            push(b, pop(a));
            return;
        }
        toh()
    }
*/

int main()
{
    int num;
    maint.top = -1;
    target.top = -1;
    buffer.top = -1;

    printf("Enter the number of elements :\n");
    scanf("%d", &n);
    printf("Enter the delay :\n");
    scanf("%d", &d);
    printf("\n");
    start_time = clock();
    maint.max = n;
    target.max = n;
    buffer.max = n;
    for(int i = n; i > 0; i--)
    {
        push(&maint, i);
    }
    printf("\033[s");
    toh(&maint, &target, &buffer, n);
    //displayto();
    end_time = clock(); 
    printf("TIME = %lf", (double)(end_time - start_time) / (CLOCKS_PER_SEC) );
}


void displayto()
{
      for(int i = n; i >= 0; i--)
      {

        if(maint.top < i)
        {
            printf("\033[31m\t||\t~\t||\t");
        }
        else
        {
            printf("\033[31m\t||\t%d \t||\t", maint.arr[i]);
        }
        if(target.top < i)
        {
            printf("\033[35m\t||\t~\t||\t");
        }
        else
        {
            printf("\033[35m\t||\ttoh(mant, buffr, targt, disk - 2);%d \t||\t", target.arr[i]);
        }
        if(buffer.top < i)
        {
            printf("\033[0m\t||\t~\t||\t");
        }
        else
        {
            printf("\033[0m\t||\t%d \t||\t", buffer.arr[i]);
        }
        printf("\n");
      }
      for(int i = 0 ; i < 3; i++)
      {
        printf("\t");
         for(int i = 0; i < 18; i++)
         {
            printf("-");
         }
         printf("\t");
      }
      printf("\n\n");
    
    return;
}