#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    p->data = data;
    p->next = NULL;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteNodeInBetween(struct Node *head, int index){
    struct Node *ptr = head;
    int i = 0;
    while(i!=index-1){
        ptr=ptr->next;
        i++;
    }
    struct Node *p = ptr->next;
    ptr->next = p->next;
    free(p);
    return head;
}

struct Node *deleteNodeWithValue(struct Node *head, int value){
    struct Node *m = head;
    struct Node *n = m->next;
    if(m->data==value){
        struct Node *p=m;
        m=m->next;
        free(p);
        return m;
    }
    while(n->data!=value && n->next!=NULL){
        m = m->next;
        n = n->next;
    }
    if(n->data==value){
        m->next=n->next;
        free(n);
    }
    return head;
}

struct Node *deleteNodeAtEnd(struct Node *head){
    struct Node *m = head;
    struct Node *n = m->next;
    while(n->next!=NULL){
        m = m->next;
        n = n->next;
    }
    m->next=NULL;
    free(n);
    return head;
}

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 1;
    head->next = second;

    // link second and third nodes
    second->data = 2;
    second->next = third;

    // terminate list at third node
    third->data = 3;
    third->next = NULL;

    head = deleteNodeWithValue(head,1);
    LinkedListTraversal(head);
    return 0;
}