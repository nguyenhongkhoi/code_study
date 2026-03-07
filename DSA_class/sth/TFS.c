#include<stdio.h>



int n, c[105][105], X[100] = {0}, visited[105] = {0};

int d = 0; ans = 10000000; 

void nhap(){
   
    scanf("%d", &n);
    for(int i =1; i <=n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &c[i][j]);
        }
    }
    
}

void Try(int i){
    for(int j = 1; j <n; j++){
        if(visited[j] == 0) {
            visited[j] = 1;
            X[i] = j;
            d += c[X[i-1]][x[i]];
            if(i == n){
                //cap nhat ket qua
                ans = ans > (d+c[X[n],1]) ? (d+c[X[n],1]) : ans;
            }
        }
        else{
            try(i+1);
        }

    }
}

int main(){
    nhap();

    return 0;
}