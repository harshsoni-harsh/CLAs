#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

int take_numeric_input();
void circular_deletable(node* head);
void circular_insert_node_begin(node* head, int data);
void circular_insert_node_end(node* head, int data);
void circular_insert_node_pos(node* head, int data, int position);
void circular_delete_node_begin(node* head);
void circular_delete_node_end(node* head);
void circular_delete_node_pos(node* head, int position);
void circular_traverse(node* head);
void circular_sort_and_print_asc(node* head);
void circular_sort_and_print_desc(node* head);

int take_numeric_input()
{
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);
    return data;
}
void circular_deletable(node* head)
{
    if(head->next == head)
    {
        printf("You can't delete an empty circular list\n");
        return;
    }
}
void circular_insert_node_begin(node* head, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
}
void circular_insert_node_end(node* head, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = head;
    node* ptr = head;
    while(ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
void circular_insert_node_pos(node* head, int data, int position)
{
    if(position==0)
    {
        circular_insert_node_begin(head, data);
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    node* ptr = head;
    int counter=0;
    while(ptr->next != head && counter<position)
    {
        ptr = ptr->next;
        counter++;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}
void circular_delete_node_begin(node* head)
{
    circular_deletable(head);
    node* ptr = head->next;
    head->next = head->next->next;
    free(ptr);
}
void circular_delete_node_end(node* head)
{
    circular_deletable(head);
    node* ptr = head;
    node* ptr2 = ptr->next;
    while(ptr2->next!=head)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    ptr->next = head;
    free(ptr2);
}
void circular_delete_node_pos(node* head, int position)
{
    circular_deletable(head);
    node* ptr = head;
    node* ptr2 = ptr->next;
    int counter = 1;
    while(ptr2->next!=head && counter<position)
    {
        counter++;
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    if(ptr2->next == head)
    {
        free(ptr2);
        ptr->next = head;
    }
    else 
    {
        ptr->next = ptr2->next;
        free(ptr2);
    }
}
void circular_traverse(node* head)
{
    node* ptr = head->next;
    printf("Printing List...\n");
    while(ptr != head)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("HEAD\n\n");
}
void circular_sort_and_print_asc(node* head)
{
    node* temp = head->next;
    int num;
    node* temp3;
    while(temp != head)
    {
        node* temp2 = head->next;
        while(temp2->next != head)
        {
            temp3 = temp2;
            temp2 = temp2->next;
            if(temp3->data > temp2->data)
            {
                num = temp3->data;
                temp3->data = temp2->data;
                temp2->data = num;
            }
        }
        temp = temp->next;
    }

    circular_traverse(head);
}
void circular_sort_and_print_desc(node* head)
{
    node* temp = head->next;
    int num;
    node* temp3;
    while(temp != head)
    {
        node* temp2 = head->next;
        while(temp2->next != head)
        {
            temp3 = temp2;
            temp2 = temp2->next;
            if(temp3->data < temp2->data)
            {
                num = temp3->data;
                temp3->data = temp2->data;
                temp2->data = num;
            }
        }
        temp = temp->next;
    }

    circular_traverse(head);
}
