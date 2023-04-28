#include <stdio.h>
#define Max_size 4

int queue[Max_size], tail=-1, head=0;
void Enqueue(int data){
    if(tail==Max_size-1) tail=-1;
    queue[++tail]=data;
}
int Dequeue(){
    if(head==Max_size) head=0;
    return queue[head++];
}
void main(){
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Enqueue(6);
    Enqueue(7);
    printf("%d\n",Dequeue());
    printf("%d\n",Dequeue());
    printf("%d\n",Dequeue());
    printf("%d\n",Dequeue());
}