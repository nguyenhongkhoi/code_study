#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 1000000
typedef struct node
{
    int day;
    int month;
    int year;
    char name[1000];
} node;

int cmp(const void *a, const void *b)
{
    node *x = (node *)a;
    node *y = (node *)b;

    if (x->year != y->year)
    {
        return x->year - y->year;
    }
    if (x->month != y->month)
    {
        return x->month - y->month;
    }
    return x->day - y->day;
}
node arr[MAX];
int cnt = -1;
int main()
{
    char s[MAX];
    while (1)
    {
        fgets(s, MAX, stdin);
        s[strcspn(s, "\n")] = '\0';
        if (strcmp(s, "*") == 0)
            break;
        cnt++;
        char *delim = " \n/-";
        char *in = strtok(s, delim);

        arr[cnt].year = atoi(in);
        arr[cnt].month = atoi(strtok(NULL, delim));
        arr[cnt].day = atoi(strtok(NULL, delim));
        strcpy(arr[cnt].name, strtok(NULL, delim));
    }
    qsort(arr, cnt + 1, sizeof(node), cmp);
    for (int i = 0; i <= cnt; i++)
    {
        printf("%d %d %d  %s\n", arr[i].year, arr[i].month, arr[i].day, arr[i].name);
    }
    return 0;
}