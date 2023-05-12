#include "dequeue.h"

void main()
{
    struct dequeue *q1=(struct dequeue*)malloc(sizeof(struct dequeue));
    q1->size=3;
    q1->front=-1;
    q1->rear=-1;
    q1->arr=(int *)malloc(sizeof(q1->size));
    while(1)
    {
        int choice;
        printf("Type 1 to Insert at rear\n");
        printf("Type 2 to Insert at Front\n");
        printf("Type 3 to Delete rear\n");
        printf("Type 4 to Delete front\n");
        printf("Type 5 to Display\n");
        printf("Type 6 to quit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                int d;
                printf("Enter data to insert: ");
                scanf("%d", &d);
                insert_rear(q1, d);
                break;
            }
            case 2:
            {
                int d;
                printf("Enter data to insert: ");
                scanf("%d", &d);
                insert_front(q1, d);
                break;
            }
            case 3:
                delete_rear(q1);
                break;
            case 4:
                delete_front(q1);
                break;
            case 5:
                display(q1);
                break;
            case 6:
                free(q1->arr);
                free(q1);
                return;
            default:
                printf("Invalid Choice\n");
        }
    }
}