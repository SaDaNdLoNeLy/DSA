#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void charCopyPaste(FILE *in, FILE *out){
    char c;
    while ((c=fgetc(in))!=EOF){
        fputc(c, out);
        putchar(c);
    }
}

int main(){
    FILE *fptr1, *fptr2;
    char filename1[] = "docfile1.txt";
    char filename2[] = "ghifile1.txt";

    fptr1 = fopen(filename1, "r");
    fptr2 = fopen(filename2, "w");

    charCopyPaste(fptr1, fptr2);
    fclose(fptr1);
    fclose(fptr2);
}