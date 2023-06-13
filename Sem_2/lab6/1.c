//reverse a given linked list.
#include "../linkedList.h"

void reverse(node* head)
{
    node* prev = head->next;
    node* next = prev->next;
    node* ptr = next->next;
    prev->next = NULL;
    while(prev!=NULL && next!=NULL)
    {
        next->next = prev;
        prev = next;
        if(ptr == NULL)
        break;
        next = ptr;
        ptr = ptr->next;
    }
    head->next = prev;
}
void main()
{
    node* head = menu();
    reverse(head);
    traverse(head);
}