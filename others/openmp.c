#include <stdio.h>
#include <omp.h>

void main()
{
    #pragma omp parallel
    printf("Running %d on %d", omp_get_thread_num(), omp_get_thread_limit());
}