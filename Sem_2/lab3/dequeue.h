#include <stdio.h>
#include <stdlib.h>

struct dequeue
{
    int front;
    int rear;
    int *arr;
    int size;
};
void insert_rear(struct dequeue *q, int data)
{
    if(q->rear >= q->size - 1)
    {
        printf("Can't insert at rear\n\n");
        return;
    }
    else if(q->rear == -1)
    {
        q->front = 0;
    }
    q->arr[++q->rear] = data;
}
void insert_front(struct dequeue *q, int data)
{
    if(q->front<1)
    {
        printf("Can't insert at front\n\n");
        return;
    }
    q->arr[--q->front]=data;
}
int delete_front(struct dequeue *q)
{
    if(q->front > q->rear)
    {
        printf("Queue is empty\n\n");
        return 0;
    }
    else if(q->front == q->rear)
    {
        q->rear = -1;
        int temp = q->arr[q->front];
        q->front=-1;
        return temp;
    }
    return q->arr[q->front++];
}
int delete_rear(struct dequeue *q)
{
    if(q->rear < q->front)
    {
        printf("Queue is empty\n\n");
        return 0;
    }
    else if(q->rear == q->front)
    {
        q->front=-1;
        int temp = q->arr[q->front];
        q->rear=-1;
        return temp;
    }
    return q->arr[q->rear--];
}
void display(struct dequeue *q)
{
    int temp = q->front;
    printf("\nPrinting Queue...\n");
    if(q->front==-1)
    {
        return;
    }
    while(temp!=q->rear)
    {
        printf("%d  ", q->arr[temp++]);
    }
    printf("%d  ", q->arr[temp]);
    printf("\n\n");
}