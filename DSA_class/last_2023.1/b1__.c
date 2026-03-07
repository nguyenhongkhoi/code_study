#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 21000

typedef struct node
{
    int id;
    char email[22];
} node;

node arr[MAX];
int cnt = 0;

int cmp(const void *a, const void *b)
{
    node *x = (node *)a;
    node *y = (node *)b;
    return strcmp(x->email, y->email);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &arr[i].id, arr[i].email);
    }
    qsort(arr, n, sizeof(node), cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", arr[i].id, arr[i].email);
    }
    return 0;
}