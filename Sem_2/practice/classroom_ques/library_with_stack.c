#include <stdio.h>
#include <stdlib.h>

typedef struct book 
{
    char title[20];
    char author[20];
    int publication_year;
    struct book *next;
}books;

void main()
{
    int number;
    printf("Enter number of books: ");
    scanf("%d", &number);
    books* dummy=(books*)malloc(sizeof(books));
    books* start=dummy;
    dummy->next=NULL;
    for(int i = 0; i<number; i++)
    {
        books *book1=(books*)malloc(sizeof(books));
        printf("\n\nEnter book's title: ");
        scanf("%s", book1->title);
        printf("Enter book's author name: ");
        scanf("%s", book1->author);
        printf("Enter book's publication year: ");
        scanf("%d", &book1->publication_year);
        book1->next=NULL;
        dummy->next=book1;
        dummy=dummy->next;
    }
    char search[20];
    int found=0;
    printf("\nEnter Book title to search: ");
    scanf("%s", search);
    books* tr=start;
    printf("\nSearching books...\n");
    for (int i=0; i<number; i++)
    {
        tr=tr->next;
        if(book->title == search);
    }
    books* roam=start;
    printf("\nPrinting books...\n");
    for (int i=0; i<number; i++)
    {
        roam=roam->next;
        printf("\nTitle: %s\n", roam->title);
        printf("author: %s\n", roam->author);
        printf("publication year: %d\n", roam->publication_year);
    }
}