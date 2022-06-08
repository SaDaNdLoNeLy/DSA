#include <stdio.h>

int isSubsetSum(int arr[], int n, int sum){
    if (sum==0)
        return 1;
    if (n==0)
        return 0;
    
    return isSubsetSum(arr, n-1, sum) || isSubsetSum(arr, n-1, sum-arr[n-1]);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    printf("%d", isSubsetSum(arr, 9, 45));
}