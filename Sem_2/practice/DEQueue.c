#include <stdio.h>

#define Max_size 5

struct queue
{
    int rear;
    int front;
    int arr[Max_size];
} q1;

void insert_Rear(struct queue *q, int data)
{
    if(q->rear==-1)
    {
        q->front=0;
    }
    else if((q->rear)==(Max_size)-1)
    {
        printf("**Can't insert at rear.**\n");
        return;
    }
    q->arr[++q->rear] = data;
}
void insert_Front(struct queue *q, int data)
{
    if(q->front<=0)
    {
        printf("**Can't insert at front.**\n");
        return;
    }
    q->arr[--q->front] = data;

}
int delete_Rear(struct queue *q)
{
    if(q->rear < q->front || q->rear==-1)
    {
        printf("**Queue is already empty.**\n");
        return 0;
    }
    else if(q->front == q->rear)
    {
        int data = q->arr[q->rear];
        q->front=-1;
        q->rear=-1;
        return data;
    }
    else
    {
        return q->arr[q->rear--];
    }
}
int delete_Front(struct queue *q)
{
    if(q->front==-1)
    {
        printf("**Queue is already empty.**\n");
        return 0;
    }
    else if(q->front == q->rear)
    {
        int data = q->arr[q->front];
        q->front=-1;
        q->rear=-1;
        return data;
    }
    else
    {
        return q->arr[q->front++];
    }    
}
void display(struct queue *q)
{
    if(q->front==-1)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("\n\n-----------------\n");
    printf("|    DEQueue    |\n");
    printf("-----------------\n");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d  ", q->arr[i]);
    }
    printf("\nFront: %d Rear: %d\n", q->front, q->rear);
    printf("\n\n");
}

void main()
{
    q1.front=-1;
    q1.rear=-1;
    struct queue *a=&q1;
    while(1)
    {
        printf("\n\n");
        printf("Type 1 to Insert\n");
        printf("Type 2 to Delete\n");
        printf("Type 3 to Display\n");
        printf("Type 4 to terminate\n");
        int choice1, choice2, input;
        scanf("%d", &choice1);
        switch(choice1)
        {
            case 1:
                a1:
                printf("Enter the data: ");
                scanf("%d", &input);
                printf("Type 1 to Insert at Front.\n");
                printf("Type 2 to Insert at Rear.\n");
                scanf("%d", &choice2);
                switch(choice2)
                {
                    case 1:
                        insert_Front(a, input);
                        break;
                    case 2:
                        insert_Rear(a, input);
                        break;
                    default:
                        printf("Invalid choice\n");
                        goto a1;
                        break;
                }
                break;
            case 2:
                a2:
                printf("Type 1 to Delete the Front.\n");
                printf("Type 2 to Delete the Rear.\n");
                scanf("%d", &choice2);
                switch(choice2)
                {
                    case 1:
                        delete_Front(a);
                        break;
                    case 2:
                        delete_Rear(a);
                        break;
                    default:
                        printf("Invalid choice\n");
                        goto a2;
                        break;
                }
                break;
            case 3:
                display(a);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}