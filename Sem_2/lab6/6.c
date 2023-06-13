//reverse first N elements of the linked list.

#include "../linkedList.h"

void reverse_n(node* head, int number);
void main()
{
    node* head = menu();
    reverse_n(head, 3);
    traverse(head);
}
void reverse_n(node* head, int number)
{
    int n=0;
    node* prev = head->next;
    node* next = prev->next;
    node* ptr = next->next;
    node* end = prev;
    while(ptr!=NULL && prev!=NULL && next!=NULL && n!=number)
    {
        int temp=number-(++n);
        
        while(temp!=0)
        {
            temp--;
            next->next = prev;
            prev=next;
            if(ptr==NULL)
            break;
            next = ptr;
            ptr = ptr->next;
        }
        if(ptr!=NULL)
        {
            ptr = ptr->next;
        }
        end->next = next;
        head->next = prev;
    }
}
// void reverse_n(node* head, int number)
// {
//     int n=0;
//     node* ptr = head->next;
//     node* ptr2 = head->next;
//     int data;
//     while((ptr2->next != NULL) && n!=number)
//     {
//         ptr = ptr2;
//         int temp=number-++n;
//         while(temp!=0)
//         {
//             temp--;
//             data = ptr->data;
//             ptr->data = ptr->next->data;
//             ptr->next->data = data;
//             ptr = ptr->next;
//             traverse(head);
//         }
//     }
// }