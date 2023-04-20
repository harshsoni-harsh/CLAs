#include <stdio.h>
#include <time.h>

int main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Doing calculations\n");
    clock_t t;
    t=clock();
    int num, verify=1, count=0;
    while(verify<size-1){
        for(int i=0; i<size-1;i++){
            if(arr[i]<=arr[i+1]){
                verify+=1;
            }
            else{
                num=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=num;
                verify=0;
            }
        }
        count+=1;
//        for(int i=0; i<size; i++){
//            printf("%d ", arr[i]);
//        }
    }
    t=clock()-t;
    double time_taken = ((double)t/CLOCKS_PER_SEC);
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\nPasses = %d\n",count);
    printf("\n Time taken is %lf\n", time_taken);
    return 0;
}