#include <stdio.h>
#include <stdlib.h>
#define S 9

int grid[S][S];

void printSolution(){
    for (int i=0; i<S; i++){
        for (int j=0; j<S; j++)
            printf(" %d", grid[i][j]);
        printf("\n");
    }
}

int check(int value, int row, int colum){
    for (int i=0; i<=row-1; i++){
        if (grid[i][colum]==value)
            return 0;
    }

    for (int j=0; j<=colum-1; j++){
        if (grid[row][j]==value)
            return 0;
    }
    row_
    for (int )
    
}

void try(int row, int colum){
    for (int value=1; value<=9; value++){
        if (check(value, row, colum)){
            grid[row][colum]=value;
            if (row==8 && colum==8)
                printSolution();
            else{
                if(colum==8)
                    try(row+1,colum);
                else 
                    try(row, colum+1);
            }
        }
    }      
}

int main(){
    try(0,0);
}

