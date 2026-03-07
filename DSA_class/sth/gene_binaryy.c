#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void print(int *arr,int n){
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return;
}

void trys(int *arr, int n, int k){
    for(int v = 0; v <= 1; v++){
        arr[k] = v;
        if(k == n-1) print(arr,n);
        else trys(arr,n,k+1);
    }
}


int main(){
    int n;
    scanf("%d",&n);
    int arr[100];
    trys(arr,n,0);
    return 0;
}