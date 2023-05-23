#include <stdio.h>

int main(){
    int low, high, factor;
    int j=0,k=0;
    printf("Enter the range of numbers: \n");
    scanf("%d %d", &low, &high);
    int nums[high+1];
    int prime[high+1];
    int composite[high+1];
    for(int i=low; i<(high+1); i++){
        factor=0;
        for(int x=1; x<i; x++){
            if(i%x==0){
                factor++;
            }
        }
        if(factor==1){
            prime[j]=i;
            
            j++;
        }
        else{
            composite[k]=i;
            
            k++;
        }
    }
    printf("\nPrime number are: \n");
    for(int a=0; a<(j); a++){
        printf("%d ",prime[a]);    
    }
    printf("\nComposite number are: \n");
    for(int b=0; b<(k); b++){
    	if(composite[b]==1){
    		printf(" \"1 is neither prime nor composite\" ");
    	}
    	else if(composite[b]==0){
    		printf(" \"0 is neither prime nor composite\" ");
    	}
    	else{
    		printf("%d ",composite[b]);
    	}
    }
    printf("\n");
    return 0;
}
