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
    int size;
    printf("Enter the size of your library: ");
    struct book books[size];
    char status[4];
    while(status[0]!='e'){
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
    printf("\nEnter the title, author, year_published of the book\n");
    scanf("%s %s %d", book1.title, book1.author, &book1.year_published);
}
int display_books(){
    FILE *fp;
    fp=fopen("book.txt", "a");
    for(int i=0; i<size; i++){
        
    }
    struct book book1;
    printf("\nEnter the title, author, year_published of the book\n");
    scanf("%s %s %d", book1.title, book1.author, &book1.year_published);
    fprintf(fp,"%s %s %d\n", book1.title, book1.author, book1.year_published);
    fclose(fp);
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
    printf("\n");
    fclose(fp1);
    return 0;
}