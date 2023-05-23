#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct queue
{
    int front;
    int rear;
    int* arr;
    int size;
} queue;
void enqueue(queue *q, int data);
int dequeue(queue *q);

void main()
{
    int count;
    printf("Enter number of processes: ");
    scanf("%d", &count);
    queue* q1=(queue*)malloc(sizeof(queue));
    q1->arr = (int*)malloc(sizeof(int)*count);
    q1->front = -1;
    q1->rear = -1;
    q1->size = count;
    int counter=0, avg=0, d=0;
    char out[count];
    while(count>counter)
    {
        printf("Enter burst time for process %d\n", ++counter);
        int data;
        scanf("%d", &data);
        enqueue(q1, data);
    }
    while(q1->rear!=q1->front)
    {
        d=dequeue(q1);
        avg+=d;
        strcat(out, d);
    }
    printf("Average waiting time: %dms\n", (int)avg/count);
    free(q1->arr);
    free(q1);
}


void enqueue(queue *q, int data)
{
    if(q->rear < q->size)
    {
        if(q->front==-1)
        {
            q->front = 0;   
        }
        q->arr[(++q->rear)%q->size] = data;
    }
    else
    {
        printf("Can't enqueue\n");
    }
}
int dequeue(queue *q)
{
    if(q->rear==q->front)
    {
        q->front=-1;
        return q->arr[--q->rear];
    }
    else if(q->rear > q->front)
    {
        return q->arr[--q->rear];
    }
    printf("Queue is empty\n");
    return 0;
}
void display(queue *q)
{
    int temp=q->front;
    printf("\nPrinting Queue...\n");
    if(q->front == -1)
    {
        printf("\n\n");
        return;
    }
    while(temp <= q->rear)
    {
        printf("%d  ", q->arr[temp++]);
    }
    printf("\nFront: %d Rear: %d", q->front, q->rear);
    printf("\n\n");
}