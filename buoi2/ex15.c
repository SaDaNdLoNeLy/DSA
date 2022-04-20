#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

void lineCopyPaste(FILE *in, FILE *out){
    char buffer[MAX];
    while ((fgets(buffer, MAX, in)) != NULL){
        fprintf(out, "%d %s", strlen(buffer), buffer);
        printf("%d %s", strlen(buffer), buffer);
    }
    
}

int main(){
    FILE *fptr1, *fptr2;
    char filename1[] = "docfile1.txt";
    char filename2[] = "ghifile4.txt";

    fptr1 = fopen(filename1, "r");
    fptr2 = fopen(filename2, "w");

    lineCopyPaste(fptr1, fptr2);
    fclose(fptr1);
    fclose(fptr2);
}