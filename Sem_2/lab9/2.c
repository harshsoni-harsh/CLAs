/*
Implement a phonebook application using a Binary Search Tree in C. Each entry should contain a
name and corresponding phone number. Provided the name, the program should display the contact
details of the matching name. Also, display the contact details of all the names in the BST in
in-order manner.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phonebookEntry
{
    char name[50];
    char phoneNumber[15];
    struct phonebookEntry* left;
    struct phonebookEntry* right;
}phonebookEntry;

phonebookEntry* insert(phonebookEntry** head, char* name, char* phoneNumber)
{
    if(*head==NULL)
    {
        phonebookEntry* new = (phonebookEntry*)malloc(sizeof(phonebookEntry));
        strcpy(new->name, name);
        strcpy(new->phoneNumber, phoneNumber);
        new->left = NULL;
        new->right = NULL;
        *head = new;
    }
    else if(strcmp(name, (*head)->name) > 0)
    {
        insert(&((*head)->right), name, phoneNumber);
    }
    else if(strcmp(name, (*head)->name) != 0)
    {
        insert(&((*head)->left), name, phoneNumber);
    }
    return *head;
}
phonebookEntry* delete(phonebookEntry** head, char* name)
{
    if(*head == NULL) return NULL;
    else if(strcmp(name, (*head)->name) > 0)
    {
        // printf("\nGoing right\n");
        (*head)->right = delete(&((*head)->right), name);
        return *head;
    }
    else if(strcmp(name, (*head)->name) < 0)
    {
        // printf("\nGoing left\n");
        (*head)->left = delete(&((*head)->left), name);
        return *head;
    }
    else
    {
        // printf("\nname found\n");
        if((*head)->left == NULL && (*head)->right == NULL)
        {
            free(*head);
            return NULL;
        }
        else if((*head)->left != NULL && (*head)->right != NULL)
        {
            phonebookEntry* big = (*head)->right;
            phonebookEntry* small = (*head)->left;

            while(big->left != NULL)
            {
                big = big->left;
            }

            big->left = small;
        }
        else if((*head)->left != NULL)
        {
            phonebookEntry* temp = (*head)->left;
            free(*head);
            return temp;
        }
        else
        {
            phonebookEntry* temp = (*head)->right;
            free(*head);
            return temp;
        }
    }
}
void display(phonebookEntry** head)
{
    if(!(*head))   return;
    display(&((*head)->left));
    printf("-  %s:%s  -", (*head)->name, (*head)->phoneNumber);
    display(&((*head)->right));
}
void search(phonebookEntry** head, char* name)
{
    if((*head) == NULL)
    {
        printf("%s is not present in bst\n", name);
    }
    else if((*head)->name == name)
    {
        printf("%s is present in bst\n", name);
    }
    else if(strcmp(name, (*head)->name) < 0)
    {
        search(&((*head)->left), name);
    }
    else
    {
        search(&((*head)->right), name);
    }
}

void main()
{
    phonebookEntry* head = NULL;
    int choice;
    char name[50];
    char phoneNumber[15];
    while(1)
    {
        printf("\nType 1 to insert\nType 2 to delete\nType 3 to display\ntype 4 to search\nType 5 to terminate\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the name: ");
                scanf("%s", name);
                printf("\nEnter the phoneNumber: ");
                scanf("%s", phoneNumber);
                head = insert(&head, name, phoneNumber);
                break;
            case 2:
                printf("\nEnter the name: ");
                scanf("%s", name);
                head = delete(&head, name);
                break;
            case 3:
                display(&head);
                break;
            case 4:
                printf("\nEnter the name: ");
                scanf("%s", name);
                search(&head, name);
                break;
            case 5:
                return;
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
}