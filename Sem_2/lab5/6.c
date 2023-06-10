#include "../circularLinkedList.h"

void search(node* head, int data)
{
    node* ptr = head->next;
    int counter = -1;
    while(ptr != head)
    {
        counter++;
        if(ptr->data == data)
        {
            printf("%d has been found at Node %d\n", data, counter);
            return;
        }
        ptr = ptr->next;
    }
    printf("Not found\n");
}
void main()
{
    node* head = (node*)malloc(sizeof(node));
    head->data=0;
    head->next=head;
    while(1)
    {
        int choice, position, num;
        printf("\n\n Type 1 for circular_insert_node_begin\t Type 2 for circular_insert_node_end\n");
        printf(" Type 3 for circular_insert_node_pos\t Type 4 for circular_delete_node_begin\n");
        printf(" Type 5 for circular_delete_node_end\t Type 6 for circular_delete_node_pos\n");
        printf(" Type 7 to display list\t Type 8 to terminate\n");
        printf(" Type 9 to search an element\n");
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
                circular_traverse(head);
                break;
            case 8:
                return;
            case 9:
                printf("Enter the searching data: ");
                scanf("%d", &num);
                search(head, num);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}