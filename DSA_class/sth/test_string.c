#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct string
{
    char data[100];
    int fre;
} string;

int cmp(const void *a, const void *b)
{
    string *x = (string *)a;
    string *y = (string *)b;
    return strcmp(x->data, y->data);
}

void lwer(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        s[i] = tolower(s[i]);
    }
    return;
}
string arr[100];
int cnt = 0;

void _check_valid(char *st)
{
    for (int i = 0; i <= cnt; i++)
    {
        if (strcmp(arr[i].data, st) == 0)
        {
            arr[i].fre++;
            return;
        }
    }
    strcpy(arr[cnt].data, st);
    arr[cnt].fre = 1;
    cnt++;
    return;
}

int main()
{
    char s[100000];
    fgets(s, 100000, stdin);
    s[strcspn(s, "\n")] = 0;
    lwer(s);
    printf("%s\n", s);
    const char *delim = " ,.\n\t";
    char *check = strtok(s, delim);
    while (check != NULL)
    {
        // printf("%s\n", check);
        _check_valid(check);
        check = strtok(NULL, delim);
    }
    qsort(arr, cnt, sizeof(string), cmp);
    for (int i = 0; i < cnt; i++)
    {
        printf("%s ", arr[i].data);
        printf("%d\n", arr[i].fre);
    }

    return 0;
}