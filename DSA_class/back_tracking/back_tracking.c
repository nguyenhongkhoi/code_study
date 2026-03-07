#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 21

int n;
int X[N];

int check(int v, int k){
    return 1;
}

void solution(){

    for(int i = 1; i <= n; i++) printf("%d", X[i]);     // sinh xau nhị phân
    printf("\n");

}

void try(int k){
    for(int v = 0; v <= 1; v++){
        if(check(v,k)){
            X[k] = v;
            if(k == n) solution();
            else try(k+1);
        }                               
    }
}

int main(){
    scanf("%d",&n);
    try(1);
    return 0;
}



// // #include <stdio.h>

// // int X[9][9];
// // int markR[9][10];
// // int markC[9][10];
// // int markS[3][3][10];
// // int count = 0;
// // int check(int i, int j, int c){
// //     if(markR[i][c]) return 0;
// //     if(markC[j][c]) return 0;
// //     if(markS[i/3][j/3][c]) return 0;                      //suduku
// //     return 1;
// // }

// // void Try(int i, int j){
// //     if(i == 9) {       
// //         count++;
// //         return;
// //     }

// //     if(X[i][j] != 0) {
// //         if(j == 8) Try(i+1, 0);
// //         else Try(i, j+1);
// //         return;
// //     }

// //     for(int c = 1; c <= 9; c++){
// //         if(check(i, j, c)){
// //             X[i][j] = c;
// //             markR[i][c] = 1;
// //             markC[j][c] = 1;
// //             markS[i/3][j/3][c] = 1;
// //             if(j == 8) Try(i+1, 0);
// //             else Try(i, j+1);
// //             markR[i][c] = 0;
// //             markC[j][c] = 0;
// //             markS[i/3][j/3][c] = 0;
// //             X[i][j] = 0;
// //         }
// //     }
// // }

// // int main(){
// //     for(int i = 0; i < 9; i++){
// //         for(int j = 0; j < 9; j++){
// //             scanf("%d", &X[i][j]);
// //             int val = X[i][j];
// //             if(val != 0){
// //                 markR[i][val] = 1;
// //                 markC[j][val] = 1;
// //                 markS[i/3][j/3][val] = 1;
// //             }
// //         }
// //     }

// //     Try(0, 0);
// //     return 0;
// // }



// #include <stdio.h>
// #define N 100
// //x[i]: chi so hang cua con hau tren cot i
// //rang buoc
// //x[i] != x[j]: khac hang
// //x[i] + i != x[j] + j: khac duong cheo chinh
// //x[i] - i != x[j] - j: khac duong cheo phu
 
// int n;
// int x[N];
// int mark[N]; //danh dau hang
// int markD1[2*N]; // danh dau cheo chinh                        //con hau
// int markD2[2*N]; // danh dau cheo phu
// int cnt;
 
// int check (int v, int k){
//     if (mark[v] == 1) return 0;
//     if (markD1[n + k - v] == 1) return 0;
//     if (markD2[k + v] == 1) return 0;
//     return 1;
// }
 
// void Try(int k){
//     if (x[k] > 0){
//         if (k == n) cnt ++;
//         else Try(k + 1);
//         return;
//     }
//     for (int r = 1; r <= n; r++){
//         if (check(r, k)){
//             x[k] = r;
//             mark[r] = 1; markD1[n+k-r] = 1; markD2[k+r] = 1;
//             if (k == n) cnt ++;
//             else Try(k + 1);
//             x[k] = 0;
//             mark[r] = 0; markD1[n+k-r] = 0; markD2[k+r] = 0;
//         }
//     }
// }
 
// void input(){
//     for (int i = 1; i < N; i++) mark[i] = 0;
//     for (int i = 0; i < 2*N; i++){
//         markD1[i] = 0;
//         markD2[i] = 0;
//     }
//     scanf ("%d", &n);
//     for (int i = 1; i <= n; i++) x[i] = 0;
//     for (int i = 1; i <= n; i++){
//         for (int j = 1; j <= n; j++){
//             int e;
//             scanf("%d", &e);
//             if (e == 1){
//                 x[j] = i;
//                 mark[i] = 1; markD1[n + j - i] = 1; markD2[i + j] = 1;
//             }
//         }
//     }
// }
 
// int main(){
//     input();
//     cnt = 0;
//     Try (1);
//     printf ("%d", cnt);
//     return 0;
// }



























