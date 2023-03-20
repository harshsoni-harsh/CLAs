#include <stdio.h>
#include <stdlib.h>

struct book{
    char title[20];
    char author[20];
    int year_published;
};
void add_book();
int display_books();

void main(){
    while(1){
        char status[4];
        printf("\nType add to add a new book, or type exit to exit the program\n");
        scanf("%s", status);
        if(status[0]=='e'){
            display_books();
        }
        else{
            add_book();
        }
    }
}

void add_book(){
    FILE *fp;
    fp=fopen("book.txt", "a");
    struct book book1;
    printf("\nEnter the title, author, year_published of the book\n");
    fprintf(fp,"%s %s %d", book1.title, book1.author, book1.year_published);
    fclose(fp);
}
int display_books(){
    char c;
    FILE *fp1;
    fp1=fopen("book.txt", "r");
    if(fp1==NULL){
        printf("Error in opening the file");
        return -1;
    }
    while((c=getc(fp1))!=EOF){
        printf("%c",c);
    }
    fclose(fp1);
    return 0;
}