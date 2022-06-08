#include <stdio.h>

int count, n;
int a[100];

void printSolution(){
    int i;
    count++;
    printf("The string number %d: ", count);
    for (i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void try(int k){
    for (int j=0; j<=1; j++){
        a[k-1]=j;
        if (k==n)
            printSolution();
        else 
            try(k+1);
    }
}

int main(){
    n=5;
    count = 0;
    try(1);
    printf("Number of strings: %d", count);
}