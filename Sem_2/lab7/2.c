#include "../doublyLL.h"

typedef struct stack
{
    int top;
    node* head;
} stack;

void push(stack* s1, int data);
int pop(stack* s1);
void display(stack* s1);

void main()
{
    stack* s1 = (stack*)malloc(sizeof(stack));
    s1->head = (node*)malloc(sizeof(node));
    int choice;
    while(1)
    {
        printf("\nType 1 to push\nType 2 to pop\nType 3 to display\nType 4 to terminate");
        scanf("%d", &choice);
        printf("\n");
        switch(choice)
        {
            case 1:
                push(s1, take_numeric_input());
                break;
            case 2:
                pop(s1);
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
void push(stack* s1, int data)
{
    insert_node_begin(&(s1->head), data);
    (s1->top)++;
}
int pop(stack* s1)
{
    delete_node_begin(&(s1->head));
    (s1->top)--;
}
void display(stack* s1)
{
    node* ptr = s1->head->next;
    printf("\nPrinting stack...\n");
    while(ptr != NULL)
    {
        printf("|%d|\n", ptr->data);
        ptr = ptr->next;
    }
}
