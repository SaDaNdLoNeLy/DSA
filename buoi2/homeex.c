#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct grade_info
{
    char name[20];
    double point;
} GRADE;

int main(){
    FILE *f1, *f2;
    GRADE *grade = malloc(25*sizeof(GRADE));
    GRADE ag;
    int i, grade_count=5, status_read, status_write; 

    int choice, sub_choice;

    do{
        printf("%20s\n", "MENU");
        printf("+--------------------------------------+\n");
        printf("| 1 | %-32s |\n", "TXT-DAT          ");
        printf("| 2 | %-32s |\n", "DISPLAY DAT      ");
        printf("| 3 | %-32s |\n", "SEARCH AND UPDATE");
        printf("| 4 | %-32s |\n", "QUIT             ");
        printf("+--------------------------------------+\n");
        printf("What is your choice: ");
        scanf("%d%*c", &choice);

        switch (choice){
        case 1:
            f1 = fopen("grade.txt", "r");
            f2 = fopen("grade.dat", "wb");
            status_read = fread(grade, sizeof(GRADE), grade_count, f1);
            status_write = fwrite(grade, sizeof(GRADE), grade_count, f2);
            if (f1 == NULL){
                printf("CANNOT READ FILE\n");
            }
            if (f2 == NULL){
                printf("CANNOT WRITE FILE\n");
            }
            if (status_read != 5 || status_write != 5){
                printf("ENCOUNTER EOF\n");
            }
            if (f1 != NULL && f2 != NULL)
            {
                printf("CONVERT SUCCESSFULLY\n");
            }
            
            fclose(f1);
            fclose(f2);
            break;
        case 2:
            f2 = fopen("grade.dat", "r");
            status_read = fread(grade, sizeof(GRADE), grade_count, f2);
            printf("Data of %d contacts in the dat file:\n", grade_count);
            for (i=0; i<grade_count; i++){
                printf("Name: %s\tGrade: %.2lf\n", grade[i].name, grade[i].point);
            }
            fclose(f2);
            break;
        case 3:
            printf("+--------------------------------------+\n");
            printf("| 1 | %-32s |\n", "SEARCH           ");
            printf("| 2 | %-32s |\n", "UPDATE           ");
            printf("+--------------------------------------+\n");
            printf("WHAT DO YOU WANT TO DO: ");
            scanf("%d%*c", &sub_choice);
            switch (sub_choice){
            case 1:
                printf("UNDER DEVELOPMENT\n");
                break;
            case 2:
                printf("ENTER STUDENT NAME: ");
                scanf("%[^\n]%*c", ag.name);
                printf("ENTER STUDENT'S GRADE: ");
                scanf("%lf%*c", &ag.point);
                f2 = fopen("grade.dat", "ab");
                fwrite(&ag, sizeof(GRADE), 1, f2);
                fclose(f2);
                grade_count++;
                break;
            }
            break;
        case 4:
            printf("THANKYOU FOR USING OUR SERVICE\n");
            break;
        }
    } while (choice != 4);
}

