#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void charCopyPaste(FILE *in, FILE *out){
    int c, new_c;
    while ((c=fgetc(in))!=EOF){
        if (isupper(c))
            new_c=tolower(c);
        else if (islower(c))
            new_c=toupper(c);
        else
            new_c = c;
        fputc(new_c, out);
        putchar(new_c);
    }
}

int main(){
    FILE *fptr1, *fptr2;
    char filename1[] = "docfile2.txt";
    char filename2[] = "ghifile2.txt";

    fptr1 = fopen(filename1, "r");
    fptr2 = fopen(filename2, "w");

    charCopyPaste(fptr1, fptr2);
    fclose(fptr1);
    fclose(fptr2);
}