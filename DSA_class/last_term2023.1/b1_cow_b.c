#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 105
int _day, _change, n;
char _name[10];
int res = 0;

int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

typedef struct data
{
    int day;
    char name[10];
    int change;
} data;

// int cmp(const void *a, const void *b)
// {
//     return *(int *)a - *(int *)b;
// }

int main()
{
    scanf("%d", &n);
    data list[MAX];
    int i = 0;
    while (n--)
    {
        // strtok
        scanf("%d", &_day);
        scanf("%s", _name);
        scanf("%d", &_change);
        list[i].day = _day;
        strcpy(list[i].name, _name);
        list[i].change = _change;
        i++;
        // if (strcmp(_name, "Sind") == 0)
        // {
        //     sind.change += _change;
        // }
        // if (strcmp(_name, "Vang") == 0)
        // {
        //     vang.change += _change;
        // }
        // if (strcmp(_name, "Jersey") == 0)
        // {
        //     jersey.change += _change;
        // }
    }
    // res = max(max(sind.change, vang.change), jersey.change);
    //  printf("%d", res);
    // qsort(list, i, sizeof(data), cmp);
    for (int j = 0; j < i; j++)
    {
        printf("%d %s %d\n", list[j].day, list[j].name, list[j].change);
    }
    return 0;
}
