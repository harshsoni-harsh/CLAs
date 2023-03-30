#include <stdio.h>
#include <stdlib.h>

struct book{
    char title[20];
    char author[20];
    int year_published;
} book[100];

void add_books();
void display_books();
int a=0;

void main(){
    int o;
    x:{
    printf("\nEnter 1 to add books\nEnter 2 to display books\n");
    scanf("%d", &o);
    if(o==1){
        add_books();
        goto x;
    }
    else if(o==2){
        display_books();
    }
    else{
        printf("Invalid Operation\n");
        exit(0);
    }
    }
}

void add_books(){
    FILE *fp;
    fp=fopen("books.txt", "w");
    printf("Enter the book's title: ");
    scanf("%s", book[a].title);
    printf("Enter the author's name: ");
    scanf("%s", book[a].author);
    printf("Enter the publication year: ");
    scanf("%d", &book[a].year_published);
    printf("\n");
    fprintf(fp, "%s %s %d\n", book[a].title, book[a].author, book[a].year_published);
    a++;
}
void display_books(){
    FILE *fp;
    fp=fopen("books.txt", "r");
    char ch;
    while (fscanf(fp, "%c", &ch) == 1)
    {
        printf("%c", ch);
    }
    fclose(fp);
}