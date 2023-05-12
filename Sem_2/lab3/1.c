#include "queue.h"

void main()
{
    struct queue *q1=(struct queue*)malloc(sizeof(struct queue));
    q1->size=20;
    q1->front=-1;
    q1->rear=-1;
    q1->arr=(int *)malloc(sizeof(q1->size));
    while(1)
    {
        int choice;
        printf("Type 1 to Enqueue\n");
        printf("Type 2 to Dequeue\n");
        printf("Type 3 to Display\n");
        printf("Type 4 to quit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                int d;
                printf("Enter data to enqueue: ");
                scanf("%d", &d);
                enqueue(q1, d);
                break;
            }
            case 2:
                dequeue(q1);
                break;
            case 3:
                display(q1);
                break;
            case 4:
                free(q1->arr);
                free(q1);
                return;
            default:
                printf("Invalid Choice\n");
        }
    }
}