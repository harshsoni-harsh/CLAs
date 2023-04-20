#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct courses{
    int id;
    char name[20];
    char instructor[20];
}a;

void main(){
    struct courses course[3]={
        {101, "math", "f1"},
        {102, "science", "f2"},
        {103, "history", "f3"}
    };
    int c;
    printf("Enter 1 to display all contents\nEnter 2 to search course\n");
    scanf("%d", &c);
    if(c==1){
        for(int i=0; i<(sizeof(course)/sizeof(a)); i++){
            printf("\nCourse id: %d\tname: %s\tinstructor: %s\t", course[i].id, course[i].name, course[i].instructor);
        }
        exit(0);
    }
    else if(c==2){
        int id;
        printf("\nEnter the course id: ");
        scanf("%d", &id);
        for(int i=0; i<(sizeof(course)/sizeof(a)); i++){
            if(course[i].id==id){
                printf("\nCourse id: %d\tname: %s\tinstructor: %s\t", course[i].id, course[i].name, course[i].instructor);
                exit(0);
            }
        }
        printf("\nNot found\n");
    }
}