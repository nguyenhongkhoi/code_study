#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100000
typedef struct string
{
    char data[MAX];
    int fre;
} string;

string arr[1000];
int cnt = 0;
void lwer(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        s[i] = tolower(s[i]);
    }
    return;
}

void check_valid(char *check)
{
    for (int i = 0; i <= cnt; i++)
    {
        if (strcmp(arr[i].data, check) == 0)
        {
            arr[i].fre++;
            return;
        }
    }
    cnt++;
    strcpy(arr[cnt].data, check);
    arr[cnt].fre = 1;
}

int main()
{
    char s[MAX];
    fgets(s, MAX, stdin);
    s[strcspn(s, "\n")] = '\0';
    lwer(s);
    printf("%s\n", s);
    char *delim = " ,.\n";
    char *check = strtok(s, delim);
    while (check != NULL)
    {
        check_valid(check);
        // printf("%s\n", check);
        check = strtok(NULL, delim);
    }
    for (int i = 0; i <= cnt; i++)
    {
        printf("%s %d\n", arr[i].data, arr[i].fre);
    }

    return 0;
}