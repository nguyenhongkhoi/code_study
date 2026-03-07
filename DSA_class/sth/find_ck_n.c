// #include<stdio.h>
// #include<math.h>

// int main(){
//     int n;
//     scanf("%d",&n);
//     int A[200]={0};
//     int i = 0;
//     while(n != 0){
//         A[i] = n % 2;
//         n /= 2;
//         i++;
//     }
//     for(int j = i - 1; j >= 0; j--) printf("%d", A[j]);
//     return 0;
//}
#include <stdio.h>

#define MOD 1000000007

long long power(long long a, long long b) {
    long long result = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

long long mod_inverse(long long a) {
    return power(a, MOD - 2);
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);

    long long factn = 1, factk = 1, factnk = 1;
    for (int i = 2; i <= n; i++) {
        factn = (factn * i) % MOD;
        if (i == k) factk = factn;
        if (i == n - k) factnk = factn;
    }

    long long denominator = (factk * factnk) % MOD;
    long long result = (factn * power(denominator,MOD - 2)) % MOD;

    printf("%lld\n", result);
    return 0;
}