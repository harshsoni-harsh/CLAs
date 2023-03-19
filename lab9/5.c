#include <stdio.h>

void main(){
    struct Employee{
        char name[20];
        int ID;
        char dept[10];
        int salary;
    };
    int size;
    printf("Enter the number of employees: ");
    scanf("%d", &size);
    struct Employee emp[size];
    for(int i=0; i<size; i++){
        printf("Enter the name, ID, department, salary for emp%d\n", i);
        scanf("%s %d %s %d", emp[i].name, &emp[i].ID, emp[i].dept, &emp[i].salary);
    }
    printf("Employees\t name\t\t ID\t\t department\t\t salary\t\t\n");
    for(int i=0; i<size; i++){
        printf("Employee%d\t %s\t\t %d\t\t %s\t\t         %d\t\t\n", i, emp[i].name, emp[i].ID, emp[i].dept, emp[i].salary);
    }
}