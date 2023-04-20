#include <stdio.h>

int main(){
    char str[10];
    for(int i=0; i<10; i++){
        str[i]=getchar();
    }
    printf("%s\n", str);
    return 0;
}
