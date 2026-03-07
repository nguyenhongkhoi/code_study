#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 1000000

int cnt = 0;
void solve(int n, char a, char b, char c)
{
    if (n <= 1)
    {
        printf("move 1 disk form %c to %c\n", a, b);
        cnt++;
        return;
    }
    solve(n - 1, a, c, b);
    solve(1, a, b, c);
    solve(n - 1, c, b, a);
    return;
}

int main()
{
    solve(4, 'a', 'b', 'c');
    printf("%d", cnt);
    return 0;
}