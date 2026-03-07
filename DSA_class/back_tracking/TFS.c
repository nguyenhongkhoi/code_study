#include <stdio.h>

int n; // số thành phố
int d[100][100]; // ma trận chi phí giữa các thành phố
int x[100]; // hành trình hiện tại
int f, f_min; // f: chi phí hiện tại, f_min: chi phí nhỏ nhất tìm được
int mark[100]; // đánh dấu thành phố đã đi qua

void Try(int k) {
    for (int v = 1; v <= n; v++) {
        if (mark[v] == 0) {
            x[k] = v;
            mark[v] = 1;
            f = f + d[x[k - 1]][x[k]];

            if (k == n) {
                if (f + d[x[n]][1] < f_min)
                    f_min = f + d[x[n]][1];
            } else {
                if (f < f_min)
                    Try(k + 1);
            }

            mark[v] = 0;
            f = f - d[x[k - 1]][x[k]];
        }
    }
}
int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &d[i][j]);

    for (int i = 1; i <= n; i++)
        mark[i] = 0;

    x[1] = 1;
    mark[1] = 1;
    f = 0;
    f_min = 1000000;

    Try(2);
    printf("%d\n", f_min);
    return 0;
}