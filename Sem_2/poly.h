#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int coefficient;
    int power;
    struct node *next;
}node;

void take_numeric_input(int* p);
void insert_node(node* head, int coefficient, int power);
void delete_node_begin(node* head);
void delete_node_end(node* head);
void delete_node_pos(node* head, int position);
void sort(node* head);
void traverse(node* head);
node* menu();

void take_numeric_input(int* p)
{
    printf("Enter data, power: ");
    scanf("%d %d", &p[0], &p[1]);
}
void insert_node(node* head, int coefficient, int power)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->coefficient = coefficient;
    temp->power = power;
    temp->next = head->next;
    head->next = temp;
    sort(head);
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
        ptr->next=NULL;
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
    if(ptr == NULL)
    {
        printf("Not found\n");
        return;
    }
    printf("Printing polynomial...\n");
    sort(head);
    while(ptr->next != NULL)
    {
        printf("(%dx^%d) + ", ptr->coefficient, ptr->power);
        ptr = ptr->next;
    }
    printf("(%dx^%d)", ptr->coefficient, ptr->power);
}
void sort(node* head)
{
    node* temp = head->next;
    int num, num2;
    node* temp3;
    while(temp != NULL)
    {
        node* temp2 = head->next;
        while(temp2->next != NULL)
        {
            temp3 = temp2;
            temp2 = temp2->next;
            if(temp3->power < temp2->power)
            {
                num = temp3->coefficient;
                num2 = temp3->power;
                temp3->coefficient = temp2->coefficient;
                temp2->coefficient = num;
                temp3->power = temp2->power;
                temp2->power = num2;
            }
        }
        temp = temp->next;
    }
}
node* menu()
{
    node* head = (node*)malloc(sizeof(node));
    head->coefficient=0;
    head->next=NULL;
    while(1)
    {
        int choice, position;
        int p[2];
        printf("\n\n Type 1 for insert_node\n");
        printf(" Type 2 for delete_node_begin\n");
        printf(" Type 3 for delete_node_end\n Type 4 for delete_node_pos\n");
        printf(" Type 5 to display list\t Type 6 to terminate\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                take_numeric_input(p);
                insert_node(head, p[0], p[1]);
                break;
            case 2:
                delete_node_begin(head);
                break;
            case 3:
                delete_node_end(head);
                break;
            case 4:
                printf("Enter the position: ");
                scanf("%d", &position);
                delete_node_pos(head, position);
                break;
            case 5:
                traverse(head);
                break;
            case 6:
                return head;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}