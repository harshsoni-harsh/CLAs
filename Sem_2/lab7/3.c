#include "../doublyLL.h"

typedef struct queue
{
    node* front;
} queue;

void enqueue(queue* s1, int data);
int dequeue(queue* s1);
void display(queue* s1);

void main()
{
    queue* s1 = (queue*)malloc(sizeof(queue));
    s1->front = (node*)malloc(sizeof(node));
    int choice;
    while(1)
    {
        printf("\nType 1 to enqueue\nType 2 to dequeue\nType 3 to display\nType 4 to terminate");
        scanf("%d", &choice);
        printf("\n");
        switch(choice)
        {
            case 1:
                enqueue(s1, take_numeric_input());
                break;
            case 2:
                dequeue(s1);
                break;
            case 3:
                display(s1);
                break;
            case 4:
                return;
            default:
                printf("Invalid case\n");
                break;
        }
    }
}
void enqueue(queue* s1, int data)
{
    node* rear;
    insert_node_end(&(s1->front), data);
}
int dequeue(queue* s1)
{
    delete_node_begin(&(s1->front));
}
void display(queue* s1)
{
    node* ptr = s1->front->next;
    printf("\nPrinting queue...\n");
    while(ptr != NULL)
    {
        printf("|%d|  ", ptr->data);
        ptr = ptr->next;
    }
}
