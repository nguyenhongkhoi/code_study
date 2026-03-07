// // #include<stdio.h>
// // #include<stdbool.h>
// // #include<stdlib.h>

// // int sol_count = 0;

// // void print_sol(int *board,int n){
// //     sol_count++;
// //     printf("sol %d: \n",sol_count );

// //     for(int i = 0; i < n; i++){
// //         for(int j=0; j< n; j++){
// //             printf("%d ",board[i*n +j]);
// //         }
// //          printf("\n");
// //     }

// // }

// // bool is_safe(int * board,int n, int row,int col){
// //     int i,j;
// //     for(i = 0; i < col; i++){
// //         if (board[row*n + i]) return false; //ktra hang ben trai
// //     }
// //     for(i = row, j=col; i >= 0 && j >= 0; i--,j--){
// //         if(board[i * n + j]) return false; //ktra hang cheo tren ben trai

// //     }
// //     for(i = row, j = col; i < n&& j >=0; i++, j--){
// //         if(board[i*n + j]) return false;
// //     }
// //     return true;
// // }

// // void solve_queen(int *board,int n, int col){
// //     if(col >= n){
// //         print_sol(board,n);
// //     }

// //     for(int i = 0; i < n; i++){
// //         if(is_safe(board,n,i,col)){
// //             board[i*n + col] = 1;
// //             solve_queen(board,n,col+1);
// //             board[i*n + col] = 0;
// //         }

// //     }
// // }




// // int main(){
// //     int n;
// //     scanf("%d",&n);
// //     int *board = (int*)calloc(n*n, sizeof(int));
// //     solve_queen(board,n,0);


// //     return 0;
// // 
// #include<stdio.h>
// #include<stdlib.h>
// #include<stdbool.h>

// int solve_sum = 0;

// void print_sol(int *board,int n){
//     printf("sol %dth\n", ++solve_sum);

//     for(int i = 0; i < n;i++){
//         for(int j = 0; j< n; j++){
//             printf("%d ",board[i*n+j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
// }

// bool is_safe(int *board, int n, int row,int col){
//     //ktra hang ben trai
//     int i,j;
//     for(int i = 0; i < col; i++){
//         if(board[row*n + i]) return false;
//     }
//     //ktra cheo ben tren trai
//     for(i = row,j=col; i >= 0 && j >= 0; i--,j--){
//         if(board[i*n +j]) return false;
//     }
//     //ktra cheo ben trai duoi
//     for(i = row, j = col; i < n&& j >= 0;i++, j--){
//         if(board[i*n +j]) return false;
//     }
//     return true;
// }

// void solve_queen(int *board, int n, int col){
//     if(col >= n){
//         print_sol(board,n);
//     }
//     //ktra n hang cua cot thu col
//     for(int i = 0; i < n; i++){
//         if(is_safe(board,n,i,col)){
//             //dat hau
//             board[i*n + col] = 1;
//             solve_queen(board, n, col+1);
//             //bo hau neu k dc
//             board[i*n + col] = 0;
//         }
//     }

// } 





// int main(){
//     int n;
//     scanf("%d",&n);
//     int *board = (int*)calloc(n*n,sizeof(int));
//     solve_queen(board,n,0);

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


int count = 0;
void print_sol(int *board, int n){
    count++;
    printf("%d\n", count);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ",board[i*n +j]);
        }
        printf("\n");
    }
    return;
}


bool is_safe(int *board, int n, int row, int col){
    int i,j;
    for(i = 0; i <  col; i++){
        if(board[row*n +i]) return false;
    }
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i*n+j]) return false;
    }
    for(i = row, j = col; i < n&& j >=0; i++, j--){
        if(board[i*n +j]) return false;
    }
    return true;
}


void solve(int *board, int n, int col){
    if(col >= n){
        print_sol(board,n);
        return;
    }
    for(int i = 0; i<n; i++){
        if(is_safe(board,n,i,col)){
            board[i*n + col] = 1;
            solve(board,n,col+1);
            
        }
        board[i*n +col] = 0; // backtrack
        
    }
}

int main(){

    int n;
    scanf("%d",&n);
    int *board = (int*)calloc(n*n,sizeof(int));
    //print_sol(board,n);
    solve(board,n,0);
}4
