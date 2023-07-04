/*
Write a menu driven C program to implement various operations of a Binary Search Tree such as
Insert, Search, Display (in-order) and Deleting a specified key.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* insert(node** head, int data)
{
    if(*head==NULL)
    {
        node* new = (node*)malloc(sizeof(node));
        new->data = data;
        new->left = NULL;
        new->right = NULL;
        *head = new;
    }
    else if(data > (*head)->data && data != (*head)->data)
    {
        insert(&((*head)->right), data);
    }
    else if(data != (*head)->data)
    {
        insert(&((*head)->left), data);
    }
    return *head;
}
node* delete(node** head, int data)
{
    if(*head == NULL) return NULL;
    else if(data > (*head)->data)
    {
        // printf("\nGoing right\n");
        (*head)->right = delete(&((*head)->right), data);
        return *head;
    }
    else if(data < (*head)->data)
    {
        // printf("\nGoing left\n");
        (*head)->left = delete(&((*head)->left), data);
        return *head;
    }
    else
    {
        // printf("\nData found\n");
        if((*head)->left == NULL && (*head)->right == NULL)
        {
            free(*head);
            return NULL;
        }
        else if((*head)->left != NULL && (*head)->right != NULL)
        {
            node* big = (*head)->right;
            node* small = (*head)->left;

            while(big->left != NULL)
            {
                big = big->left;
            }

            big->left = small;
        }
        else if((*head)->left != NULL)
        {
            node* temp = (*head)->left;
            free(*head);
            return temp;
        }
        else
        {
            node* temp = (*head)->right;
            free(*head);
            return temp;
        }
    }
}
void display(node** head)
{
    if(!(*head))   return;
    display(&((*head)->left));
    printf("-%d-", (*head)->data);
    display(&((*head)->right));
}
void search(node** head, int data)
{
    if((*head) == NULL)
    {
        printf("%d is not present in bst\n", data);
    }
    else if((*head)->data == data)
    {
        printf("%d is present in bst\n", data);
    }
    else if((*head)->data > data)
    {
        search(&((*head)->left), data);
    }
    else
    {
        search(&((*head)->right), data);
    }
}

void main()
{
    node* head = NULL;
    int choice, data;
    while(1)
    {
        printf("\nType 1 to insert\nType 2 to delete\nType 3 to display\ntype 4 to search\nType 5 to terminate\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                head = insert(&head, data);
                break;
            case 2:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                head = delete(&head, data);
                break;
            case 3:
                display(&head);
                break;
            case 4:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                search(&head, data);
                break;
            case 5:
                return;
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
}