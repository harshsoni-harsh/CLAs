#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insert_node(node *head, int data, int position)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head;
    node *temp = head;
    int counter = 0;
    while (counter < position)
    {
        counter++;
        head = head->next;
    }
    head->next = ptr;
    ptr->next = temp;
}
void delete_node_begin(node *head)
{
    if (head == NULL)
    {
        printf("List is empty!!! Deletion is not possible\n");
        exit(1);
    }
    node *temp1 = head;
    node *temp2 = head;
    if (temp1->next == temp1)
    {
        free(temp1);
    }
    while (temp1->next == temp2)
    {
        temp1 = temp1->next;
    }
    head = temp2->next;
    temp1->next = head;
    free(temp2);
}
void delete_node(node *head, int position)
{
    if (head->next == head)
    {
        printf("List is empty!!! Deletion is not possible\n");
        exit(1);
    }
    node *temp1 = head;
    node *temp3 = temp1->next;
    int len = 1;
    for (; temp3->next != head; temp1 = temp1->next, len++)
    position %= len;
    if (position == len-1)
    {
        node *temp2 = temp1->next;
        head->next = head->next->next;
        free(temp2);
    }
    temp1 = head->next;
    int counter = 1;
    while (counter < position)
    {
        counter++;
        temp1 = temp1->next;
    }
    node *temp2 = temp1->next;
    temp1->next = temp1->next->next;
    free(temp2);
}
void main()
{
    node *head = (node *)malloc(sizeof(node));
    head->data = 0;
    head->next = head;
    insert_node(head, 5, 0);
    insert_node(head, 6, 1);
    delete_node(head, 1);
}