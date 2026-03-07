#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100000

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    while (1)
    {
        char s[MAX];
        fgets(s, MAX, stdin);
        s[strcspn(s, "\n")] = '\0';
        printf("%s\n", s);
        char *delim = " .,\n\t?!@";
        char *check = strtok(s, delim);
        char *status = check;
        if (strcmp(status, "quit") == 0)
            break;
        check = strtok(NULL, delim);
        int x = atoi(check);
        printf("%s \n%d\n", status, x);
    }

    return 0;
}