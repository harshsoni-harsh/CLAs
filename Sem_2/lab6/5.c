//string is a palindrome or not using the linked lists.
#include "../linkedList.h"

void main()
{
    node* word = (node*)malloc(sizeof(node));
    node* pal_word = (node*)malloc(sizeof(node));
    char c='a';
    while(1)
    {
        scanf("%c", &c);
        if(c=='\0' || c=='\n')
        break;
        insert_node_end(word,c);
        insert_node_begin(pal_word,c);
    }
    int is_pal = 1;
    while(word!=NULL)
    {
        if(word->data != pal_word->data)
        {
            is_pal = 0;            
            break;
        }
        word = word->next;
        pal_word = pal_word->next;
    }
    if(is_pal)
    {
        printf("It's a palindrome\n");
    }
    else
    {
        printf("It's not a palindrome\n");
    }
}