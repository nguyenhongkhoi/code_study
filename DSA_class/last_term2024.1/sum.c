#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n % 2 != 0)
        n--;
    int cnt = (n - 2) / 2 + 1;
    int sum = (n + 2) * cnt / 2;
    printf("%d", sum);
    return 0;
}
// https://www.studocu.vn/vn/document/truong-dai-hoc-bach-khoa-ha-noi/c-programming-language/de-thi-cuoi-ky-20241-lap-trinh-c-co-ban-it3230/147333826