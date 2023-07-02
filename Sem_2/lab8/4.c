#include "../doublyLL.h"

void sort_asc(node* head)
{
    node* temp = head;
    while(temp->next != NULL)
    {
        node* temp2 = head;
        while(temp2->next != NULL)
        {
            node* temp3 = temp2->next;
            node* temp4 = temp3->next;
            if(temp4){
                if(temp3->data > temp4->data)
                {
                    temp2->next = temp4;
                    temp4->prev = temp2;

                    temp3->next = temp4->next;
                    
                    temp4->next = temp3;
                    temp3->prev = temp4;
                    
                    if(temp->prev)
                    temp = temp->prev;
                }
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}
void sort_desc(node* head)
{
    sort_asc(head);
    node* prev = head->next;
    node* next = prev->next;
    node* ptr = next->next;
    prev->next = NULL;
    while(prev != NULL && next!= NULL)
    {
        next->next = prev;
        prev->prev = next;
        prev = next;
        if(!ptr)    break;
        next = ptr;
        ptr = ptr->next;
    }
    head->next = prev;
}
void main()
{
    node* head = menu();
    traverse(&head,0);
    printf("\nDescending\n");
    sort_desc(head);
    traverse(&head, 0);
    printf("\nAscending\n");
    sort_asc(head);
    traverse(&head, 0);
}