#include<stdio.h>
#include<stdlib.h>

int n;
int *arr;

void input(){
    scanf("%d",&n);
    arr = (int*)calloc(n,sizeof(int));
    return;
}

void print_sol(int *arr, int n){
    for(int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void Try(int k){
    for(int v = 0; v <= 1; v++){
        arr[k] = v;
        if(k == n-1) print_sol(arr,n);
        else Try(k+1); 
    }
    return;
}

int main(){
    input();
    Try(0);
    return 0;
}