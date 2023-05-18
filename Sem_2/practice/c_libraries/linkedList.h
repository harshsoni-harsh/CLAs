#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* initializeList();
node* insertAtFirst(node* head, int data);
node* insertAtEnd(node* head, int data);
node* insertAtIndex(node* head, int data, int index);
node* deleteAtFirst(node *head);
node* deleteAtEnd(node *head);
node* traverse(node *head);
int search(node *head, int data);
void is_list_exists(node *head);

node* initializeList()
{
    node* stack = (node*)malloc(sizeof(node));
    stack->data = 0;
    stack->next = NULL;
    return stack;
}
void is_list_exists(node *head)
{
    if (head == NULL)
    {
        printf("Doesn't exists!\n");
        exit(1);
    }
}
node* insertAtFirst(node* head, int data)
{
    is_list_exists(head);
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = 0;
    ptr->next = head;
    head->data = data;
    return ptr;
}
node* insertAtEnd(node* head, int data)
{
    is_list_exists(head);
    node* start = head;
    while(head->next!=NULL)
    {
        head = head->next;
    }
    node* ptr = (node*)malloc(sizeof(node));
    head->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
    return start;
}
node* insertAtIndex(node* head, int data, int index)
{
    node* start=head;
    int counter=1;
    node* new1 = initializeList();
    new1->data = data;
    while(head->next!=NULL)
    {
        if(counter==index)
            break;
        counter++;
        head = head->next;
    }
    node* temp=head->next;
    head->next = new1;
    new1->next = temp;
    return start;
}
node* deleteAtFirst(node *head)
{
    is_list_exists(head);
    node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
node* deleteAtEnd(node *head)
{
    is_list_exists(head);
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    node* start = head;
    node* ptr = start->next;
    while(ptr->next != NULL)
    {
        start = start->next;
        ptr = ptr->next;
    }
    start->next = NULL;
    free(ptr);
    return head;
}
node* traverse(node *head)
{
    is_list_exists(head);
    node *ptr=head->next;
    while(ptr!=NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return head;
}
int search(node *head, int data)
{
    is_list_exists(head);
    node *ptr=head->next;
    int counter=0;
    while(ptr!=NULL)
    {
        if(ptr->data == data)
        {
            return counter;
        }
        counter++;
        ptr = ptr->next;
    }
    printf("Data not found!\n");
    return -1;
}
