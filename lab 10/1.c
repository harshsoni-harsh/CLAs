#include <stdio.h>

void main(){
    char filename[20];
    printf("Enter the filename: ");
    scanf("%s", filename);
    int a;
    printf("Type 1 opening and reading file\nType 2 for creating and writing file\n");
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
        default:
        {
            printf("Invalid Input");
            break;
        }
    }
    printf("\n");
}
