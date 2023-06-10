#include "../circularLinkedList.h"

void main()
{
    node* head = (node*)malloc(sizeof(node));
    head->data=0;
    head->next=head;
    while(1)
    {
        int choice, position;
        printf("\n\n Type 1 for circular_insert_node_begin\t Type 2 for circular_insert_node_end\n");
        printf(" Type 3 for circular_insert_node_pos\t Type 4 for circular_delete_node_begin\n");
        printf(" Type 5 for circular_delete_node_end\t Type 6 for circular_delete_node_pos\n");
        printf(" Type 7 to display list\t Type 8 to terminate\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                circular_insert_node_begin(head, take_numeric_input());
                break;
            case 2:
                circular_insert_node_end(head, take_numeric_input());
                break;
            case 3:
                printf("Enter the position: ");
                scanf("%d", &position);
                circular_insert_node_pos(head, take_numeric_input(), position);
                break;
            case 4:
                circular_delete_node_begin(head);
                break;
            case 5:
                circular_delete_node_end(head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                circular_delete_node_pos(head, position);
                break;
            case 7:
                circular_sort_and_print_asc(head);
                circular_sort_and_print_desc(head);
                break;
            case 8:
                return;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}