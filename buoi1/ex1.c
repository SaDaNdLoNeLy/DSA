#include <stdio.h>

int countNum(int n){
    int i, sum=0;
    for (i=1; i<=n; i++){
        if ((i%3)==0 && (i%5)==0)
            sum+=i;
        else if((i%3)==2||(i%5==3))
            sum+=i;
    }
    return sum;
}

int main(){
    int n;

    printf("Enter the number n: ");
    scanf("%d%*c", &n);
    printf("The total of all number that satisfy the conditions: %d", countNum(n));
}