#include "../doublyLL.h"

void main()
{
    node* head = menu();
    int max, min, temp;
    node* ptr = head->next;
    if(ptr != NULL)
    {
        max = ptr->data;
        min = ptr->data;
    }
    else
    {
        printf("List is empty\n");
    }
    while(ptr != NULL)
    {
        temp = ptr->data;
        if(temp > max)
        {
            max = temp;
        }
        if(temp < min)
        {
            min = temp;
        }
        ptr = ptr->next;
    }
    printf("Min: %d\nMax: %d\n", min, max);
}