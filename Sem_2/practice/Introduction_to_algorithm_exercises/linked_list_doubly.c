#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    return ptr;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1 && index!=0)
    {
        p = p->next;
        i++;
    }
    if(index==0){
        head=insertAtFirst(head, data);
        return head;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next->prev = ptr;
    p->next = ptr;
    ptr->prev = p;
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
    p->prev = ptr;
    p->data = data;
    p->next = NULL;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next->prev = ptr;
    prevNode->next = ptr;
    ptr->prev = prevNode;
    return head;
}
/*
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

*/
void LinkedListTraversal(struct Node *ptr)
{
    printf("%d\n", ptr->data);
    do{
        ptr=ptr->next;
        printf("%d\n", ptr->data);
    }while(ptr->next!=NULL);
    do{
        printf("%d\n", ptr->data);
        ptr=ptr->prev;
    }while(ptr!=NULL);
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
    head->prev = NULL;
    head->next = second;

    // link second and third nodes
    second->data = 2;
    second->prev = head;
    second->next = third;

    // terminate list at third node
    third->data = 3;
    third->prev = second;
    third->next = NULL;

    head = insertAtIndex(head,6, 2);
    LinkedListTraversal(head);
    return 0;
}