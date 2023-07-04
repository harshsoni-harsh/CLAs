#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

int take_numeric_input();
void insert_node_begin(node* *head, int data);
void insert_node_end(node* *head, int data);
void insert_node_pos(node* *head, int data, int position);
void delete_node_begin(node* *head);
void delete_node_end(node* *head);
void delete_node_pos(node* *head, int position);
void traverse(node* *head, bool reverse);
int deletable(node* *head);
node* menu();

int take_numeric_input()
{
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);
    return data;
}
void insert_node_begin(node* *head, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = (*head)->next;
    temp->prev = *head;
    if((*head)->next != NULL)
    {
        (*head)->next->prev = temp;
    }
    (*head)->next = temp;
}
void insert_node_end(node* *head, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    node* ptr = *head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    temp->prev = ptr;
    ptr->next = temp;
}
void insert_node_pos(node* *head, int data, int position)
{
    if(position==0)
    {
        insert_node_begin(head, data);
        return;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    node* ptr = *head;
    int counter=0;
    while(ptr->next != NULL && counter<position)
    {
        ptr = ptr->next;
        counter++;
    }
    node* temp2 = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
    temp->next = temp2;
    temp2->prev = temp;
}
void delete_node_begin(node* *head)
{
    if(deletable(head))
    {
        node* ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }
}
void delete_node_end(node* *head)
{
    if(deletable(head))
    {
        node* ptr = *head;
        node* ptr2 = (*head)->next;
        if(ptr2==NULL)
        {
            printf("\nList is empty\n");
        }
        while(ptr->next!=NULL && ptr2->next!=NULL)
        {
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        free(ptr2);
        ptr->next=NULL;
    }
}
void delete_node_pos(node* *head, int position)
{
    if(deletable(head))
    {
        node* ptr = (*head)->next;
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
        else 
        {
            node* ptr3 = ptr2->next;
            free(ptr2);
            ptr->next = ptr3;
            ptr3->prev = ptr;
        }
    }
}
void traverse(node* *head, bool reverse)
{
    if(deletable(head))
    {
        if(!reverse)
        {
            node* ptr = (*head)->next;
            printf("Printing List...\n");
            while(ptr != NULL)
            {
                printf("%d -> ", ptr->data);
                ptr = ptr->next;
            }
            printf("NULL\n\n");
        }
        else
        {
            node* ptr = (*head)->next;
            while(ptr->next != NULL)
            {
                ptr=ptr->next;
            }
            printf("Printing List...\n");
            while(ptr != *head)
            {
                printf("%d -> ", ptr->data);
                ptr = ptr->prev;
            }
            printf("HEAD\n\n");
        }
    }
}
int deletable(node* *head)
{
    if((*head)->next == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    return 1;
}
node* menu()
{
    node* head = (node*)malloc(sizeof(node));
    head->data=0;
    head->next=NULL;
    head->prev=NULL;
    while(1)
    {
        int choice, position;
        printf("\n\n Type 1 for insert_node_begin\t Type 2 for insert_node_end\n");
        printf(" Type 3 for insert_node_pos\t Type 4 for delete_node_begin\n");
        printf(" Type 5 for delete_node_end\t Type 6 for delete_node_pos\n");
        printf(" Type 7 to display list\t Type 8 to terminate\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert_node_begin(&head, take_numeric_input());
                break;
            case 2:
                insert_node_end(&head, take_numeric_input());
                break;
            case 3:
                printf("Enter the position: ");
                scanf("%d", &position);
                insert_node_pos(&head, take_numeric_input(), position);
                break;
            case 4:
                delete_node_begin(&head);
                break;
            case 5:
                delete_node_end(&head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                delete_node_pos(&head, position);
                break;
            case 7:
                printf("Type 0 to print in forward direction\n");
                printf("Type 1 to print in reverse direction\n");
                scanf("%d", &position);
                traverse(&head, position);
                break;
            case 8:
                return head;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return head;
}