#include <stdio.h>

int main(){
    int size;
    printf("Enter the size of matrix: ");
    scanf("%d", &size);

    int A[size][size], B[size][size], C[size][size];

    int i, j, k;
    for (i=0; i<size; i++){
        printf("Enter the value of row %d array A: ", i+1);
        for (j=0; j<size; j++)
            scanf("%d", &A[i][j]);
        scanf("%*c");
    }

    for (i=0; i<size; i++){
        printf("Enter the value of row %d array B: ", i+1);
        for (j=0; j<size; j++)
            scanf("%d", &B[i][j]);
        scanf("%*c");
    }

    for (i=0; i<size; i++){
        for (j=0; j<size;j++){
            for (k=0; k<size; k++)
                C[i][j]=A[i][k]*B[k][j];
        }
    }

    printf("The product of AxB:\n");
    for (i=0; i<size; i++){
        for (j=0; j<size; j++)
            printf("| %2d |", C[i][j]);
        printf("\n");
    }
}



