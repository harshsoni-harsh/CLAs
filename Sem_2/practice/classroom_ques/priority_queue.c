#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int priority;
    struct node* next;
}node;

node* initializeQueue();
node* insert(node* head, int data, int priority);
node* delete(node *head);
node* traverse(node *head);
void is_list_exists(node *head);

void main()
{
    node* q1 = initializeQueue();
    q1 = insert(q1, 9, 2);
    q1 = insert(q1, 5, 0);
    q1 = insert(q1, 1, 0);
    q1 = insert(q1, 10, 10);
    q1 = insert(q1, 3, 2);
    q1 = delete(q1);
    q1 = traverse(q1);
}

node* initializeQueue()
{
    node* list = (node*)malloc(sizeof(node));
    list->data = 0;
    list->priority = 0;
    list->next = NULL;
    return list;
}
void is_list_exists(node *head)
{
    if (head == NULL)
    {
        printf("Doesn't exists!\n");
        exit(1);
    }
}
node* insert(node* head, int data, int priority)
{
    node* start=head;
    int counter=head->priority;
    node* new = initializeQueue();
    new->priority = priority;
    new->data = data;
    // printf("head: %d-%d priority: %d\n\n", head->data, counter, priority);
    while(head->next!=NULL)
    {
        if(priority>=counter)
            break;
        head = head->next;
        counter=head->priority;
        // printf("head: %d-%d priority: %d\n\n", head->data, counter, priority);
    }
    if(start->priority < priority)
    {
        start->priority = priority;
    }
    node* temp=head->next;
    head->next = new;
    new->next = temp;
    return start;
}
node* delete(node *head)
{
    is_list_exists(head);
    node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
node* traverse(node *head)
{
    is_list_exists(head);
    node *ptr=head->next;
    while(ptr!=NULL)
    {
        printf("%d-%d  ", ptr->data, ptr->priority);
        ptr = ptr->next;
    }
    printf("\n");
    return head;
}
