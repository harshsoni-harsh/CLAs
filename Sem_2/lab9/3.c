/*
Design a student grade tracking system using a Binary Search Tree in C. Each node represents a
student, with associated grades. the program should be able search for a particular student and print
the grade of that student. Also, display all the student (in-order) details and identify the highest and
lowest performing students from the BST.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[50];
    char grade;
    struct student *left;
    struct student *right;
} student;

student *insert(student **head, char *name, char grade)
{
    if (*head == NULL)
    {
        student *new = (student *)malloc(sizeof(student));
        strcpy(new->name, name);
        new->grade = grade;
        new->left = NULL;
        new->right = NULL;
        *head = new;
    }
    else if (strcmp(name, (*head)->name) > 0)
    {
        insert(&((*head)->right), name, grade);
    }
    else if (strcmp(name, (*head)->name) != 0)
    {
        insert(&((*head)->left), name, grade);
    }
    return *head;
}
student *delete(student **head, char *name)
{
    if (*head == NULL)
        return NULL;
    else if (strcmp(name, (*head)->name) > 0)
    {
        // printf("\nGoing right\n");
        (*head)->right = delete (&((*head)->right), name);
        return *head;
    }
    else if (strcmp(name, (*head)->name) < 0)
    {
        // printf("\nGoing left\n");
        (*head)->left = delete (&((*head)->left), name);
        return *head;
    }
    else
    {
        // printf("\nname found\n");
        if ((*head)->left == NULL && (*head)->right == NULL)
        {
            free(*head);
            return NULL;
        }
        else if ((*head)->left != NULL && (*head)->right != NULL)
        {
            student *big = (*head)->right;
            student *small = (*head)->left;

            while (big->left != NULL)
            {
                big = big->left;
            }

            big->left = small;
        }
        else if ((*head)->left != NULL)
        {
            student *temp = (*head)->left;
            free(*head);
            return temp;
        }
        else
        {
            student *temp = (*head)->right;
            free(*head);
            return temp;
        }
    }
}
void display(student **head, student **max, student **min)
{
    if ((*head) == NULL)
        return;
    if (strcmp((*max)->name, "invalid") == 0)
    {
        (*min)->grade = (*head)->grade;
        strcpy((*min)->name, (*head)->name);
        (*max)->grade = (*head)->grade;
        strcpy((*max)->name, (*head)->name);
    }
    display(&((*head)->left), max, min);
    printf("-  %s:%c  -", (*head)->name, (*head)->grade);
    if ((*head)->grade > (*min)->grade)
    {
        (*min)->grade = (*head)->grade;
        strcpy((*min)->name, (*head)->name);
    }
    if ((*head)->grade < (*max)->grade)
    {
        (*max)->grade = (*head)->grade;
        strcpy((*max)->name, (*head)->name);
    }
    // printf("\n%d: %s\n", strcmp((*max)->name, "invalid"), (*max)->name);
    display(&((*head)->right), max, min);
}
void search(student **head, char *name)
{
    if ((*head) == NULL)
    {
        printf("%s is not present in bst\n", name);
    }
    else if (strcmp(name, (*head)->name) == 0)
    {
        printf("%s is present in bst\n", name);
    }
    else if (strcmp(name, (*head)->name) < 0)
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
    student *head = NULL;
    int choice;
    char name[50];
    char grade;
    student *max = (student *)malloc(sizeof(student));
    student *min = (student *)malloc(sizeof(student));
    while (1)
    {
        printf("\nType 1 to insert\nType 2 to delete\nType 3 to display\ntype 4 to search\nType 5 to terminate\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the name, grade: ");
            scanf("%s %c", name, &grade);
            head = insert(&head, name, grade);
            break;
        case 2:
            printf("\nEnter the name: ");
            scanf("%s", name);
            head = delete (&head, name);
            break;
        case 3:
            strcpy(max->name, "invalid");
            display(&head, &max, &min);
            printf("\nMax: %s:%c\nMin: %s:%c\n", (max)->name, (max)->grade, (min)->name, (min)->grade);
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