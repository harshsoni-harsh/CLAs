#include <stdio.h>

void extreme(int *a,int q);

void main(){
    int y=3,b=10;
    int x[b];
    int *p=&x[0];
    printf("Enter 10 integers: ");
    for(int i=0; i<b; i++){
        scanf("%d", &x[i]);
    }
    extreme(p, b);
}

void extreme(int *a, int q){
    int size=q;
    int temp=*a;
    int arr[size];
    int num;
    
    printf("Given array is \n");
    for(int i=0; i<size; i++){
        printf("%d ",*(a +i));
    }
    printf("\n");
    for(int i=0; i<q; i++){
        arr[i]=*(a+i);
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(arr[j+1]<=arr[j]){
                num=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=num;
            }
        }
    }
    printf("%d is min, %d is max\n", arr[0], arr[size-1]);
}