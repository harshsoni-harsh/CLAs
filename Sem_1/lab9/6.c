#include <stdio.h>

void main(){
    struct DayData{
        float temp, rainfall;
    };
    int len;
    float avg_t=0, avg_r=0;
    printf("Enter the number of days: ");
    scanf("%d", &len);
    struct DayData data[len];
    for(int i=0; i<len; i++){
        printf("\nEnter temperature, rainfall for day%d: ", i+1);
        scanf("%f %f",&data[i].temp, &data[i].rainfall);
        avg_t+=data[i].temp;
        avg_r+=data[i].rainfall;
    }
    printf("\nAverage temperature is %f\n", avg_t/len);
    printf("Average rainfall is %f\n", avg_r/len);
}