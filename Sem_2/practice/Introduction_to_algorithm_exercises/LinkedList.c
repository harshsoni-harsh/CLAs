#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* insertAtFirst(node* head, int data);
node* insertAtEnd(node* head, int data);
node* deleteAtFirst(node *head);
node* deleteAtEnd(node *head);
node* traverse(node *head);

int main()
{
    node* n1=(node*)malloc(sizeof(node));
    n1->data = 0;
    n1->next = NULL;
    n1 = traverse(n1);
    // n1 = insertAtFirst(n1, 5);
    // n1 = insertAtFirst(n1, 4);
    // n1 = insertAtFirst(n1, 3);
    // n1 = insertAtEnd(n1, 2);
    n1 = deleteAtEnd(n1);
    n1 = traverse(n1);
    return 0;
}

node* insertAtFirst(node* head, int data)
{
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = 0;
    ptr->next = head;
    head->data = data;
    return ptr;
}
node* insertAtEnd(node* head, int data)
{
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
node* deleteAtFirst(node *head)
{
    node* ptr=head;
    if(head==NULL)
    return NULL;
    ptr=ptr->next;
    free(head);
    return ptr;
}
node* deleteAtEnd(node *head)
{
    if(head==NULL)
        return head;
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
    node *ptr=head->next;
    printf("Printing list....\n");
    if(head == NULL)
    return head;
    while(ptr!=NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return head;
}