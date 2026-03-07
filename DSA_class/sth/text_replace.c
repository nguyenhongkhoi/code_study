#include <stdio.h>
#include <stdlib.h> // For abs()
#include <stdbool.h>

int n;
int count = 0;
int x[100];
int board[100][100] = {0}; // x[i] = hàng đặt hậu ở cột i

bool check(int col, int row)
{
    // Duyệt qua các cột đã đặt hậu trước đó
    for (int i = 1; i < col; ++i)
    {
        // Kiểm tra trùng hàng: x[i] == row
        // Kiểm tra trùng đường chéo: abs(x[i] - row) == abs(i - col)
        if (x[i] == row || abs(x[i] - row) == abs(i - col))
        {
            return false;
        }
    }
    return true;
}

void Try(int k)
{ // Đặt hậu cho cột k
    if (k > n)
    {
        count++;
        // In ra một cấu hình
        for (int i = 1; i <= n; ++i)
        { // printf("%d ", x[i]);
            board[i][x[i]] = 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                printf("%d ", board[i][j]);
                if (j == n)
                    printf("\n");
            }
        }
        printf("\n");
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                board[i][j] = 0;
            }
        }
        return;
    }

    for (int v = 1; v <= n; ++v)
    { // Thử đặt hậu ở cột k vào hàng v
        if (check(k, v))
        {
            x[k] = v;
            Try(k + 1);
        }
    }
}

int main()
{
    printf("Enter N: ");
    scanf("%d", &n);
    Try(1);
    printf("Number of solutions: %d\n", count);
    return 0;
}