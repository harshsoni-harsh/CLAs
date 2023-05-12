#include "queue.h"

void main()
{
    struct c_queue2 *q1=(struct c_queue2*)malloc(sizeof(struct c_queue2));
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
                c_enqueue2(q1, d);
                break;
            }
            case 2:
                c_dequeue2(q1);
                break;
            case 3:
                c_display2(q1);
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