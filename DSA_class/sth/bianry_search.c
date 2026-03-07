#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int _check_num(int *arr, int n, int k)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    printf("input arr\n");
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int k;
    printf("find num: \n");
    scanf("%d", &k);
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    int res = _check_num(arr, n, k);
    if (res != -1)
    {
        printf("arr has %d at posit %d", k, res);
    }
    else
    {
        printf("deo co");
    }
    return 0;
}