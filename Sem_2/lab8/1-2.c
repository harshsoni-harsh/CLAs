#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *insert(node *root, int n)
{
    if (root == NULL)
    {
        node *new = (node *)malloc(sizeof(node));
        new->left = NULL;
        new->right = NULL;
        new->data = n;
        return new;
    }
    else if (n % 2 == 0)
    {
        root->left = insert(root->left, n);
    }
    else
    {
        root->right = insert(root->right, n);
    }
    return root;
}
node* delete(node **root, int element)
{
    node *temp = *root;
    node *temp2 = *root;
    if((*root) == NULL)
    {
        printf("Not found\n");
        return NULL;
    }
    else if((*root)->data == element)
    {
        node* left = (*root)->left;
        node* right = (*root)->right;
        if((*root)->left && (*root)->right)
        {
            node* temp = (*root)->right;
            (*root)->right->left = (*root)->left;
            free(*root);
            return temp;
        }
        else if(element%2==0){free(*root);    return left;}
        else{free(*root);                return right;}
    }
    else if(element % 2 == 0)
    {
        (*root)->left = delete(&((*root)->left), element);
    }
    else
    {
        (*root)->right = delete(&((*root)->right), element);
    }
    return *root;
}
bool search(node **root, int element)
{
    node *temp = *root;
    node *temp2 = *root;
    if (element % 2 == 0)
    {
        while (temp != NULL && temp->data != element)
        {
            temp2 = temp;
            temp = temp->left;
        }
        if(temp == NULL)    return false;
        else if (temp->data == element)
        {
            return true;
        }
        return false;
    }
    else
    {
        while (temp != NULL && temp->data != element)
        {
            temp2 = temp;
            temp = temp->right;
        }
        if(temp == NULL)    return false;
        else if (temp->data == element)
        {
            return true;
        }
        return false;
    }
}
void inorderTraversal(node *root)
{
    node *temp = root;
    if (temp == NULL)
        return;
    inorderTraversal(temp->left);
    printf("-%d-", temp->data);
    inorderTraversal(temp->right);
}
void postorderTraversal(node *root)
{
    node *temp = root;
    if (temp == NULL)
        return;
    postorderTraversal(temp->left);
    postorderTraversal(temp->right);
    printf("-%d-", temp->data);
}
void preorderTraversal(node *root)
{
    node *temp = root;
    if (temp == NULL)
        return;
    printf("-%d-", temp->data);
    preorderTraversal(temp->left);
    preorderTraversal(temp->right);
}
void main()
{
    node *root = NULL;
    int choice, data;
    while (1)
    {
        printf("\nType 1 to insert, Type 2 to delete, Type 3 to display, Type 4 to search, Type 5 to terminate\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("\nEnter the data to delete: ");
            scanf("%d", &data);
            root = delete (&root, data);
            break;
        case 3:
            printf("\nType 1 for inorder\nType 2 for postorder\nType 3 for preorder\n");
            scanf("%d", &data);
            switch (data)
            {
            case 1:
                inorderTraversal(root);
                break;
            case 2:
                postorderTraversal(root);
                break;
            case 3:
                preorderTraversal(root);
                break;
            default:
                printf("\nInvalid traversal");
                break;
            }
            printf("\n");
            break;
        case 4:
            printf("\nEnter the data to search: ");
            scanf("%d", &data);
            printf("%d in tree? %d\n", data, search(&root, data));
            break;
        case 5:
            return;
        default:
            printf("\nInvalid choice");
            break;
        }
    }
}