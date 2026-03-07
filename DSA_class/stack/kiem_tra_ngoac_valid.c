#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 1000000

char arr[MAX];
int top = -1;

void push(char x)
{
    top++;
    arr[top] = x;
}

void pop()
{
    if (top >= 0)
    {
        top--;
    }
}

bool _check(char x)
{
    if (x == '}' && arr[top] == '{')
    {
        pop();
        return true;
    }
    if (x == ')' && arr[top] == '(')
    {
        pop();
        return true;
    }
    if (x == ']' && arr[top] == '[')
    {
        pop();
        return true;
    }
    return false;
}

int main()
{
    char input[100];
    bool stt = true;
    scanf("%s", input);
    printf("%s\n", input);
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '{' || input[i] == '(' || input[i] == '[')
        {
            push(input[i]);
        }
        else
        {
            bool x = _check(input[i]);
            if (x)
            {
                continue;
            }
            else
            {
                stt = false;
                break;
            }
        }
    }
    if (stt && top == -1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}