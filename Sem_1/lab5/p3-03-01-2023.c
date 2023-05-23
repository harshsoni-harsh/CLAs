#include <stdio.h>

int main(){
    int arr[5]={10,23,24,25,30};
    int high=4, low=0,i=0;
    int mid, search, yes=0;
    printf("Enter the number to search: \n");
    scanf("%d", &search);
    while(yes==0){
        if(high<low-1){
            break;
        }
        else{
            mid=(high+low)/2;
            if(arr[mid]<search){
                low+=mid;
            }
            else if(arr[mid]==search){
                printf("%d is the index of %d \n", mid, search);
                yes=1;
            }
            else if(arr[mid+1]==search){
                printf("%d is the index of %d \n", mid+1, search);
                yes=1;
            }
            else{
                high-=mid;
            }
            i++;
        }
    }
    if(yes!=1){
        printf("Not found \n");
    }
}
