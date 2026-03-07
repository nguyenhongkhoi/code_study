#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    // char name;
    int change;
} data;

int main()
{
    scanf("%d", &n);
    data sind, vang, jersey;
    sind.change = 0;
    vang.change = 0;
    jersey.change = 0;
    while (n--)
    {
        // strtok
        scanf("%d", &_day);
        scanf("%s", &_name);
        scanf("%d", &_change);
        if (strcmp(_name, "Sind") == 0)
        {
            sind.change += _change;
        }
        if (strcmp(_name, "Vang") == 0)
        {
            vang.change += _change;
        }
        if (strcmp(_name, "Jersey") == 0)
        {
            jersey.change += _change;
        }
    }
    res = max(max(sind.change, vang.change), jersey.change);
    printf("%d", res);

    return 0;
}