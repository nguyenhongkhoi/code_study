#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
int main()
{
    long long n;
    scanf("%lld", &n);
    long long sum = 0;
    if (n <= 1)
    {
        printf("%lld", sum);
        return 0;
    }

    if (n % 2 != 0)
        n--;

    long long cnt = (n - 2) / 2 + 1;
    sum = (n + 2) * cnt / 2;
    printf("%lld", sum);

    return 0;
}