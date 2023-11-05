#include <stdio.h>

float func(int a, float guess, int times)
{
    if(times<=0)  return guess;
    return func(a, 0.5*(guess + a/guess), times-1);
}

void main()
{
    float x = func(39, 9.0, 20);
    printf("%f",x);
}