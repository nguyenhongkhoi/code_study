#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int A[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int max = A[0];
    int current = A[0];

    for(int i = 1; i < n; i++) {
        if(current < 0)
            current = A[i];
        else
            current += A[i];

        if(current > max)
            max = current;
    }

    printf("%d\n", max);
    return 0;
}





























