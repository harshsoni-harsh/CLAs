#include <stdio.h>

void main(){
    struct Rectangle{
        float height, breadth;
    }rec1;
    printf("Enter the dimensions of rectangle: ");
    scanf("%f %f", &rec1.height, &rec1.breadth);
    printf("Area is %f\nPerimeter is %f\n", rec1.height*rec1.breadth, 2*(rec1.height+rec1.breadth));
}