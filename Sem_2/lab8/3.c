#include "../linkedList.h"

node* swap2(node** head)
{
    if((*head)==NULL || (*head)->next == NULL)
        return *head;
    node* temp = (*head)->next;
    node* temp2 =  temp->next;
    temp->next = *head;
    (*head)->next = swap2(&temp2);

    return temp;
}

void main()
{
    node* head = (node*)malloc(sizeof(node));
    for(int i=1; i<6; i++)
    {
        insert_node_end(head, i);
    }
    traverse(head);
    head->next = swap2(&(head->next));
    traverse(head);
}