/////////////////
//List Reversal//
/////////////////


#include "../c_libraries/linkedList.h"

node* reverse(node* n1)
{
    node* prev = NULL;
    node* next = NULL;
    node* last = NULL;
    node* current = n1;
    node* shift = n1;
    
    int temp=0;
    while(shift->next!=NULL)
    {
        temp=shift->data;
        shift->data = shift->next->data;
        shift->next->data = temp;
        shift = shift->next;
    }
    
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        last = prev;
    }
    return prev;
}

void main()
{
    node* n1=initializeList();
    n1 = insertAtEnd(n1, 5);
    n1 = insertAtEnd(n1, 6);
    n1 = insertAtEnd(n1, 7);
    n1 = insertAtEnd(n1, 8);
    n1 = insertAtEnd(n1, 9);
    
    n1 = reverse(n1);
    traverse(n1);
}
