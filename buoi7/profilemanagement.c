#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Profile{
    char id[20];
    char email[100];
    double grade;
    struct Profile* next;
} Profile;

Profile *first, *last;

void changeProfile(){
    char id[20];
    double grade;
    printf("Enter the student ID for changing data: ");
    scanf("%[^\n]%*c", id);
    printf("Enter new grade: ");
    scanf("%lf", &grade);
    Profile* found;
    for (Profile *cur = first; cur != NULL; cur = cur->next){
        if(strcmp(cur->id, id)==0){
            cur->grade = grade;
            printf("Successfull\n");
            break;
        }
    }
}

void countPass(){
    int passNum=0;
    for (Profile *cur=first; cur != NULL; cur = cur->next){
        if (cur->grade >= 5.0)
            passNum++;
    }
    printf("The number of students have passed the course: %d\n", passNum);
}
