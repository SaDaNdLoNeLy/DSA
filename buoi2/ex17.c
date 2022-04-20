#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 80

void blockCopyPaste(FILE *in, FILE *out){
    int size;
    char b_fer[MAX+1];
    while (!feof(in)){
        size = fread(b_fer, 1, MAX, in);
        fwrite(b_fer, 1, size, out);
    }
}

int main(){

    FILE *fptr1, *fptr2;
    char filename1[25];
    char filename2[25];
    printf("Enter file to copy: ");
    scanf("%[^\n]%*c", filename1);

    printf("Enter destination file: ");
    scanf("%[^\n]%*c", filename2);

    fptr1 = fopen(filename1, "r");
    fptr2 = fopen(filename2, "w");

    blockCopyPaste(fptr1, fptr2);
    fclose(filename1);
    fclose(filename2);
}