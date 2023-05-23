#include <stdio.h>
#include <stdlib.h>

typedef struct book 
{
    char title[20];
    char author[20];
    int publication_year;
}books;

void main()
{
    books *book1=(books*)malloc(sizeof(books));
    printf("\n\nEnter book's title: ");
    scanf("%s", book1->title);
    printf("Enter book's author name: ");
    scanf("%s", book1->author);
    printf("Enter book's publication year: ");
    scanf("%d", &book1->publication_year);
    
    printf("\nPrinting book...\n");
    printf("\nTitle: %s\n", book1->title);
    printf("author: %s\n", book1->author);
    printf("publication year: %d\n", book1->publication_year);
    free(book1);
}