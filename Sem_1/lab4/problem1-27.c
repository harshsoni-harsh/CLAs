#include <stdio.h>

int main(){
    int ram_class, ram_age, ram_marks_math, ram_marks_science;
    int shyam_class, shyam_age, shyam_marks_math, shyam_marks_science;
    //classes
    printf("Enter Ram and shyam classes \n");
    scanf("%d %d", &ram_class, &shyam_class);
    printf("\n They are in same class: ");
    printf("%d \n",ram_class==shyam_class);
    //ages
    printf("Enter Ram and shyam ages \n");
    scanf("%d %d", &ram_age, &shyam_age);
    printf("\n Ram is younger to Shyam: ");
    printf("%d \n",ram_age<shyam_age);
    //marks in maths
    printf("Enter Ram and shyam marks in maths \n");
    scanf("%d %d", &ram_marks_math, &shyam_marks_math);
    printf("Ram marks in maths is more than shyam: ");
    printf("%d \n",ram_marks_math>shyam_marks_math);
    //marks in science
    printf("Enter Ram and shyam marks in science \n");
    scanf("%d %d", &ram_marks_science, &shyam_marks_science);
    printf("\n Ram marks in science is more than shyam: ");
    printf("%d \n",ram_marks_science>shyam_marks_science);

    return 0;
}
