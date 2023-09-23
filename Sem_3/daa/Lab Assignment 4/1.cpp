// Max heapify

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

void max_heapify(node* head)
{
    if(head == NULL) return;
    node* temp = head;
    int a=head->data, b = head->data;
    if(temp->left)
    {
        a = temp->left->data;
    }
    if(temp->right)
    {
        b = temp->right->data;
    }
    int max = (a>b)?a:b;
    if(max > temp->data && max == temp->left->data)
    {
        int da = temp->data;
        temp->data = max;
        temp->left->data = da;
    }
    else if(max > temp->data && max == temp->right->data)
    {
        int da = temp->data;
        temp->data = max;
        temp->right->data = da;
    }
    max_heapify(temp->left);
    max_heapify(temp->right);
}
node* findLastNode(node* head)
{
    if(head == NULL)
    {
        return head;
    }
    if(head->left== NULL || head->right == NULL)
    return head;
    node* b = findLastNode(head->right);
    node* a =  findLastNode(head->left);
    if(a)
    {
        return a;
    }
    return b;
}
node* appendToTree(node* head, int x)
{
    node* n = findLastNode(head);
    node* a = (node*)malloc(sizeof(node));
    a->data = x;
    a->left = NULL;
    a->right = NULL;
    if (n == NULL) return a;
    if(n->left == NULL) n->left = a;
    else n->right = a;
    return head;
}
void traversal(node* head)
{
    if(head == NULL) return;
    printf("%d ", head->data);
    traversal((head->left));
    traversal((head->right));
}

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements: ");
    int x;
    node* head = NULL;
    for (int i=0; i<size; i++)
    {
        scanf("%d", &x);
        head = appendToTree(head, x);
    }
    traversal(head);
    max_heapify(head);
    traversal(head);
}