// #include <stdio.h>
// #include<string.h>
// int sum(char a[20], char b[20], int length){
//     int temp = 0;
    
//    for(int i = length - 1; i >= 0; i--){
       
//         int sum  = a[i] - '0' + b[i] -'0';      
//         res[i] = sum + temp + '0';
//         temp = sum / 10;

//    }



// }

// char res[20];

// int main (){
// char a[20] , b[20];
// scanf("%s",&a);
// scanf("%s",&b);

// // fill 0 in dau day
// if(strlen(a) > strlen(b)){
//     int length = strlen(a);
//     int gap = strlen(a) - strlen(b);

//     for(int i = strlen(b) - 1; i >= 0; i--){
//         b[i + gap] = a[i];    

//         }
//     for(int i = 0; i < gap; i++){
//         b[i] = '0';
//     }

//   }else if(strlen(b) > strlen(a)){
//     int gap = strlen(b) - strlen(a);
//     int length = strlen(b);

//     for(int i = strlen(a) - 1; i >= 0; i--){
//         a[i + gap] = a[i];    

//         }
//     for(int i = 0; i < gap; i++){
//         a[i] = '0';
//     }

//   }else{
//     int length = strlen(a);
//   }
//   sum(a,b,length);
    
// printf("%s %s \n",b,res);
//  return 0; 

// }


// /*#include <stdio.h>
// #include <string.h>

// void sum(char a[20], char b[20], int res[20], int length) {
//     int temp = 0;
//     for (int i = length - 1; i >= 0; i--) {
//         int s = (a[i] - '0') + (b[i] - '0') + temp;
//         res[i] = s % 10;
//         temp = s / 10;
//     }
//     if (temp > 0) {
       
//         for (int i = length; i > 0; i--) {
//             res[i] = res[i - 1];
//         }
//         res[0] = temp;
//         length++;
//     }
    
//     for (int i = 0; i < length; i++) {
//         printf("%d", res[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int res[21] = {0}; 
//     char a[21], b[21];
//     scanf("%s", a);
//     scanf("%s", b);

//     int len_a = strlen(a);
//     int len_b = strlen(b);
//     int length = len_a > len_b ? len_a : len_b;

   
//     if (len_a < length) {
//         memmove(a + (length - len_a), a, len_a + 1);
//         for (int i = 0; i < length - len_a; i++) {
//             a[i] = '0';
//         }
//     }
//     if (len_b < length) {
//         memmove(b + (length - len_b), b, len_b + 1);
//         for (int i = 0; i < length - len_b; i++) {
//             b[i] = '0';
//         }
//     }

//     sum(a, b, res, length);
//     return 0;
// }*/
#include <stdio.h>
#include <string.h>
#include <math.h>

char res[20];

int main(){
char a[20], b[20];
scanf("%s %s", &a, &b);

int length = strlen(a) > strlen(b) ? strlen(a) : strlen(b);

if(length > strlen(a)){
    memmove(a + (length - strlen(a)), a, strlen(a) + 1);
    for(int i = 0; i < length - strlen(a); i++)   a[i] = '0';
    
}else if(length > strlen(b)){
    memmove(b+(length - strlen(b)), b,strlen(b) + 1);
    for(int i = 0; i < length; i++){
        b[i] = '0';
    }

}
printf("%s",a);
    return 0;
}



