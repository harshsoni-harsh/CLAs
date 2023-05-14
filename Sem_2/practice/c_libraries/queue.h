#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int rear;
    int* arr;
    int size;
} queue;
typedef struct c_queue
{
    int front;
    int rear;
    int* arr;
    int size;
    int counter;
} c_queue;  
typedef struct c_queue2
{
    int front;
    int rear;
    int* arr;
    int size;
} c_queue2;

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
void c_enqueue(c_queue *q, int data)
{
    if(q->counter <= q->size)
    {
        q->arr[(++q->rear)%(q->size)] = data;
        q->counter++;
    }
    else
    {
        printf("Can't enqueue\n");
    }
}
int c_dequeue(c_queue *q)
{
    if(q->counter>0)
    {
        q->counter--;
        return q->arr[(++q->front)%(q->size)];
    }
    printf("Queue is empty\n");
    return 0;
}
void c_display(c_queue *q)
{
    int temp=q->counter;
    int head=q->front;
    printf("\nPrinting Queue...\n");
    // printf("counter: %d\n", q->counter);
    if(temp==0)
    {
        // printf("Front: %d Rear: %d", q->front, q->rear);
        printf("\n\n");
        return;
    }
    while(temp != 0)
    {
        head++;
        head%=(q->size);
        printf("%d  ", q->arr[head]);
        temp--;
    }
    // printf("Front: %d Rear: %d", q->front, q->rear);
    printf("\n\n");
}
void c_enqueue2(c_queue2 *q, int data)
{
    if(q->front==-1)
    {
        q->front=0;
        ++q->rear;
    }
    if(q->front <= q->rear)
    {
        q->arr[++q->rear] = data;
    }
    else
    {
        printf("Can't enqueue\n");
    }
}
int c_dequeue2(c_queue2 *q)
{
    if(q->front != q->rear)        return q->arr[q->front++];
    printf("Queue is empty\n");    return 0;
}
void c_display2(c_queue2 *q)
{
    int head=q->front;
    printf("\nPrinting Queue...\n");
    if(head==-1)
    {
        // printf("Front: %d Rear: %d", q->front, q->rear);
        printf("\n\n");
        return;
    }
    while(head != q->rear)
    {
        printf("%d  ", q->arr[++head]);
        if(head>=q->size)   head-=q->size;
    }
    // printf("Front: %d Rear: %d\n\n", q->front, q->rear);
}