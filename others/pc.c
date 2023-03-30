#include <stdio.h>
#include <omp.h>

void main(){
    omp_set_num_threads(7900);
    #pragma omp parallel
    printf("hello \n");
}