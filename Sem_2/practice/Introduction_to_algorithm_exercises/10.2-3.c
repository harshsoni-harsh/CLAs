#include "../c_libraries/linkedList.h"

node* initializeStack();
node* enqueue(node* stack, int data);
node* dequeue(node* stack);
node* display(node* head);

int main()
{
    node* n1=initializeStack();
    n1 = display(n1);
    n1 = enqueue(n1, 5);
    n1 = display(n1);
    n1 = enqueue(n1, 4);
    n1 = display(n1);
    n1 = enqueue(n1, 3);
    n1 = display(n1);
    n1 = dequeue(n1);
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
node* enqueue(node* stack, int data)
{
    stack = insertAtEnd(stack, data);
    return stack;
}
node* dequeue(node* stack)
{
    stack = deleteAtFirst(stack);
    return stack;
}
node* display(node* head)
{
    printf("Printing queue....\n");
    head = traverse(head);
    return head;
}