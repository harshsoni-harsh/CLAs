#include <stdio.h>
#include <stdlib.h>

void main(){
    int a=0;
    while(a!=3){
        char filename[20];
        printf("Enter the filename: ");
        scanf("%s", filename);
        printf("Type 1 opening and reading file\nType 2 for creating and writing file\nType 3 to Exit\n");
        scanf("%d", &a);
        switch(a){
            case 1:
            {
                FILE *fp;
                fp=fopen(filename, "r");
                if(fp==NULL){
                    printf("File not found\n");
                    break;
                }
                char ch[100];
                fscanf(fp, "%[^\n]s", ch);
                printf("%s", ch);
                fclose(fp);
                break;
            }
            case 2:
            {
                FILE *fp1;
                fp1=fopen(filename, "w");
                char ch[100];
                printf("Enter the input: ");
                getchar();
                scanf("%[^\n]s", ch);
                fprintf(fp1, "%s", ch);
                fclose(fp1);
                break;
            }
            case 3:
            exit(0);
            default:
            {
                printf("Invalid Input");
                break;
            }
        }
        printf("\n");
    }
}
