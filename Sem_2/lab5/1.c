#include "linkedList.h"

void main()
{
    node* head = (node*)malloc(sizeof(node));
    head->data=0;
    head->next=NULL;
    while(1)
    {
        int choice, position;
        printf("\n\n Type 1 for insert_node_begin\t Type 2 for insert_node_end\n");
        printf(" Type 3 for insert_node_pos\t Type 4 for delete_node_begin\n");
        printf(" Type 5 for delete_node_end\t Type 6 for delete_node_pos\n");
        printf(" Type 7 to display list\t Type 8 to terminate\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert_node_begin(head, take_numeric_input());
                break;
            case 2:
                insert_node_end(head, take_numeric_input());
                break;
            case 3:
                printf("Enter the position: ");
                scanf("%d", &position);
                insert_node_pos(head, take_numeric_input(), position);
                break;
            case 4:
                delete_node_begin(head);
                break;
            case 5:
                delete_node_end(head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                delete_node_pos(head, position);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                return;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
