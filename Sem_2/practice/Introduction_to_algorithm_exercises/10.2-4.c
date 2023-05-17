#include "../c_libraries/linkedList.h"

void main()
{
    node* n1=initializeList();
    n1 = insertAtFirst(n1, 5);
    n1 = insertAtFirst(n1, 6);
    n1 = insertAtFirst(n1, 7);
    int s = search(n1, 7);
    if(s!=-1)
    {
        printf("Found at %d\n", s);
    }
}