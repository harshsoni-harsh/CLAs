///////////////
/////Error/////
///////////////


#include "../c_libraries/queue.h"

void push(c_queue *q1, int data)
{
    c_enqueue(q1, data);
}
int pop(c_queue *q1, c_queue *q2)
{
    while (q1->counter > 1)
    {
        c_enqueue(q2, c_dequeue(q1));
    }
    int temp = c_dequeue(q1);
    while (q2->counter > 0)
    {
        c_enqueue(q1, c_dequeue(q2));
    }
    return temp;
}
void stack_display(c_queue *q1, c_queue *q2)
{
    while (q1->front <= q1->rear)
    {
        push(q2, pop(q1, q2));
    }
    c_display(q2);
    while (q2->front <= q2->rear)
    {
        push(q1, pop(q2, q1));
    }
}
void main()
{
    c_queue *q1 = (c_queue *)malloc(sizeof(c_queue));
    c_queue *q2 = (c_queue *)malloc(sizeof(c_queue));
    q1->front = -1;
    q1->rear = -1;
    q1->size = 100;
    q1->counter = 0;
    q1->arr = (int *)malloc(sizeof(int) * q1->size);
    q2->front = -1;
    q2->rear = -1;
    q2->size = 100;
    q2->counter = 0;
    q2->arr = (int *)malloc(sizeof(int) * q1->size);

    push(q1, 5);
    push(q1, 4);
    push(q1, 3);
    stack_display(q1, q2);
    pop(q1, q2);
    stack_display(q1, q2);
    pop(q1, q2);
    stack_display(q1, q2);

    free(q1->arr);
    free(q1);
    free(q2->arr);
    free(q2);
}