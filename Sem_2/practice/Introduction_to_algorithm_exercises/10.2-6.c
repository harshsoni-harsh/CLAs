#include "../c_libraries/linkedList.h"

node* mergeNodes(node* a, node* b)
{
    node *n3=initializeList();
    node *start = n3;
    n3->next=a->next;
    while(n3->next!=NULL)
    {
        n3 = n3->next;
    }
    n3->next=b->next;
    return start;
}
void main()
{
    node* n1=initializeList();
    n1 = insertAtEnd(n1, 5);
    n1 = insertAtEnd(n1, 6);
    n1 = insertAtEnd(n1, 7);
    n1 = insertAtEnd(n1, 8);
    n1 = insertAtEnd(n1, 9);
    node* n2=initializeList();
    n2 = insertAtEnd(n2, 45);
    n2 = insertAtEnd(n2, 46);
    n2 = insertAtEnd(n2, 47);
    n2 = insertAtEnd(n2, 48);
    n2 = insertAtEnd(n2, 49);
    
    traverse(mergeNodes(n1,n2));
}
