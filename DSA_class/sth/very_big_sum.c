#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    char x[20], y[20];
    int a[20] = {0}, b[20] = {0}, sum[21] = {0};
    int temp = 0;
    scanf("%s %s", x, y);
    // fgets(x, 20, stdin);
    // x[strcspn(x, "\n")] = '\0';
    // fgets(y, 20, stdin);
    // y[strcspn(y, "\n")] = '\0';
    // printf("%s\n%s\n", x, y);
    int leng_a = strlen(x);
    int leng_b = strlen(y);
    int leng_max = leng_a > leng_b ? leng_a : leng_b;
    // printf("%d\n", leng_max);
    for (int i = leng_a - 1; i >= 0; i--)
    {
        a[leng_a - 1 - i] = x[i] - '0';
    }
    for (int i = leng_b - 1; i >= 0; i--)
    {
        b[leng_b - 1 - i] = y[i] - '0';
    }
    // for (int i = 0; i < leng_a; i++)
    //     printf("%d", a[i]);
    // printf("\n");
    // for (int i = 0; i < leng_b; i++)
    //     printf("%d", b[i]);
    // printf("\n");
    for (int i = 0; i < leng_max; i++)
    {
        sum[i] = a[i] + b[i] + temp;
        temp = sum[i] / 10;
        sum[i] = sum[i] % 10;
    }
    if (temp != 0)
    {
        leng_max++;
        sum[leng_max - 1] = temp;
    }
    for (int i = leng_max - 1; i >= 0; i--)
    {
        printf("%d", sum[i]);
    }

    return 0;
}