#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

int take_numeric_input();
void insert_node_begin(node* head, int data);
void insert_node_end(node* head, int data);
void insert_node_pos(node* head, int data, int position);
void delete_node_begin(node* head);
void delete_node_end(node* head);
void delete_node_pos(node* head, int position);
void sort_and_print_asc(node* head);
void sort_and_print_desc(node* head);
void traverse(node* head);
void search(node* head, int data);

int take_numeric_input()
{
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);
    return data;
}
void insert_node_begin(node* head, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
}
void insert_node_end(node* head, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    node* ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
void insert_node_pos(node* head, int data, int position)
{
    if(position==0)
    {
        insert_node_begin(head, data);
        return;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    node* ptr = head;
    int counter=0;
    while(ptr->next != NULL && counter<position)
    {
        ptr = ptr->next;
        counter++;
    }
    node* temp2 = ptr->next;
    ptr->next = temp;
    temp->next = temp2;
}
void delete_node_begin(node* head)
{
    node* ptr = head->next;
    free(head);
    head = ptr;
}
void delete_node_end(node* head)
{
    node* ptr = head;
    node* ptr2 = head->next;
    while(ptr->next!=NULL && ptr2->next!=NULL)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    if(ptr2==NULL)
    {
        free(ptr);
        head = NULL;
    }
    else
    {
        free(ptr2);
        ptr->next==NULL;
    }
}
void delete_node_pos(node* head, int position)
{
    node* ptr = head;
    node* ptr2 = ptr->next;
    int counter = 1;
    while(ptr->next != NULL && ptr2->next!=NULL && counter<position)
    {
        counter++;
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    if(ptr2->next == NULL)
    {
        free(ptr2);
        ptr->next = NULL;
    }
    else if(ptr->next == NULL)
    {
        printf("List is already empty\n");
    }
    else 
    {
        node* ptr3 = ptr2->next;
        free(ptr2);
        ptr->next = ptr3;
    }
}
void traverse(node* head)
{
    node* ptr = head->next;
    printf("Printing List...\n");
    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n\n");
}
void sort_and_print_asc(node* head)
{
    node* temp = head->next;
    int num;
    node* temp3;
    while(temp != NULL)
    {
        node* temp2 = head->next;
        while(temp2->next != NULL)
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

    traverse(head);
}
void sort_and_print_desc(node* head)
{
    node* temp = head->next;
    int num;
    node* temp3;
    while(temp != NULL)
    {
        node* temp2 = head->next;
        while(temp2->next != NULL)
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

    traverse(head);
}
void search(node* head, int data)
{
    node* ptr = head;
    int counter = -1;
    while(ptr != NULL)
    {
        counter++;
        ptr = ptr->next;
        if(ptr->data == data)
        {
            printf("%d has been found at Node %d\n", data, counter);
            return;
        }
    }
    printf("Not found\n");
}