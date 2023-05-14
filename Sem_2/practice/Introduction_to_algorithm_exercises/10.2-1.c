#include "../c_libraries/linkedList.h"

node* initializeStack();
node* push(node* stack, int data);
node* pop(node* stack);
node* display(node* head);

int main()
{
    node* n1=initializeStack();
    n1 = display(n1);
    n1 = push(n1, 5);
    n1 = display(n1);
    n1 = push(n1, 4);
    n1 = display(n1);
    n1 = push(n1, 3);
    n1 = display(n1);
    n1 = pop(n1);
    n1 = display(n1);
    return 0;
}

node* initializeStack()
{
    node* stack = (node*)malloc(sizeof(node));
    stack->data = 0;
    stack->next = NULL;
    return stack;
}
node* push(node* stack, int data)
{
    stack = insertAtEnd(stack, data);
    return stack;
}
node* pop(node* stack)
{
    stack = deleteAtEnd(stack);
    return stack;
}
node* display(node* head)
{
    printf("Printing stack....\n");
    head = traverse(head);
    return head;
}