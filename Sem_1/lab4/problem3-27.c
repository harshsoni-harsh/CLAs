#include <stdio.h>

int main(){
    int radius, length, len_rect_1, len_rect_2, len_tri_h, len_tri_b;
    char c[20];
    printf("What geometry do want area of: ");
    scanf("%s", c);
    if(c[0]=='c' || c[0]=='C'){
        printf("input the radius of a circle ");
        scanf("%d", &radius);
        printf("The area is %0.2f", 3.14*radius*radius);
    }
    else if(c[0]=='s' || c[0]=='S'){
        printf("input the length of a square ");
        scanf("%d", &length);
        printf("The area is %d", length*length);
    }
    else if(c[0]=='r' || c[0]=='R'){
        printf("input the length of a sides of rectangle ");
        scanf("%d %d", &len_rect_1, &len_rect_2);
        printf("The area is %d", len_rect_1*len_rect_2);
    }
    else if(c[0]=='t' || c[0]=='T'){
        printf("input the height and base length of a triangle ");
        scanf("%d %d", &len_tri_b, &len_tri_h);
        printf("The area is %0.2f", len_tri_b*len_tri_h*0.5);
    }
    return 0;
}
