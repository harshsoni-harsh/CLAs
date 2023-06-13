//add, subtract two ordered polynomial expressions using the linked list.
#include "../poly.h"

node* add_sub_poly(node* pol1, node* pol2, bool subtract);
void main()
{
    printf("Enter polynomial 1\n");
    node* pol1 = menu();
    printf("Enter polynomial 2\n");
    node* pol2 = menu();
    node* pol3 = add_sub_poly(pol1, pol2, 0);
    traverse(pol3);
    printf("\n");
}
node* add_sub_poly(node* pol1, node* pol2, bool subtract)
{
    node* ptr = pol1->next;
    node* ptr2 = pol2->next;
    node* pol3 = (node*)malloc(sizeof(node));
    pol3->next = NULL;
    node* start = pol3;
    while(ptr!=NULL || ptr2!=NULL)
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->next = NULL;
        if((ptr!=NULL && ptr2!=NULL) && ptr->power == ptr2->power)
        {
            temp->coefficient = ptr->coefficient + ptr2->coefficient * (1*(!subtract) - 1*subtract);
            temp->power = ptr->power;
            ptr = ptr->next;
            ptr2 = ptr2->next;
            if(temp->coefficient == 0)
            continue;
        }
        else if((ptr!=NULL && ptr2==NULL) || ptr->power > ptr2->power)
        {
            temp->coefficient = ptr->coefficient;
            temp->power = ptr->power;
            ptr = ptr->next;
        }
        else if(ptr2!=NULL)
        {
            temp->coefficient = ptr2->coefficient * (1*(!subtract) - 1*subtract);
            temp->power = ptr2->power;
            ptr2 = ptr2->next;
        }
        pol3->next = temp;
        pol3 = pol3->next;
    }
    return start;
}
