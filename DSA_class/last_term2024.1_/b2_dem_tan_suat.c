#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 1000000

typedef struct string
{
    char data[256];
    int fre;
} string;

string arr[MAX];
int cnt = -1;

void lwer(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        s[i] = tolower(s[i]);
    }
    return;
}

void solve(char *check)
{
    for (int i = 0; i <= cnt; i++)
    {
        if (strcmp(check, arr[i].data) == 0)
        {
            arr[i].fre++;
            return;
        }
    }
    cnt++;
    arr[cnt].fre = 1;
    strcpy(arr[cnt].data, check);
    return;
}
int cmp(const void *a, const void *b)
{
    string *x = (string *)a;

    string *y = (string *)b;

    return (x->fre - y->fre);
}

int main()
{
    char s[MAX];
    fgets(s, MAX, stdin);
    s[strcspn(s, "\n")] = '\0';
    lwer(s);
    // printf("%s\n", s);
    char *delim = " \n.,\t";
    char *check = strtok(s, delim);
    while (check != NULL)
    {
        solve(check);
        check = strtok(NULL, delim);
    }
    qsort(arr, cnt + 1, sizeof(string), cmp);
    for (int i = 0; i <= cnt; i++)
    {
        printf("%s %d\n", arr[i].data, arr[i].fre);
    }

    return 0;
}