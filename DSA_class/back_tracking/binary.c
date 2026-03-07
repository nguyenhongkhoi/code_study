#include<stdio.h>

int n;
int N[21] = {0};
int cnt = 0;
void sol(){
    for(int i = 1; i<=n;i++) printf("%d",N[i]);
    printf("\n");
    return;
}

int check(){
    for(int i = 1; i <= n; i++){
        if(N[i] == 1 && N[i+1] == 1) return 0;
        
    }
    return 1;

}

void try(int k){
    for(int v = 0; v <=1; v++){
        N[k] = v;
        if(k == n ) {if(check()) sol();}

        else {try(k+1);}

    }

}


int main(){
    scanf("%d",&n);
    try(1);
    return 0;
}