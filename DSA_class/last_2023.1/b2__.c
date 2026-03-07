#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 21000

int arr[1000000] = {0};
int cnt = 0;
typedef struct node
{
    int data;
    struct node *next;
} node;

node *makeNode(int x)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}

void insertHead(node **head, int x)
{
    if (x < 0 || arr[x] == 1)
        return;
    node *p = makeNode(x);
    p->next = *head;
    *head = p;
    arr[x] = 1;
    cnt++ return;
}

void insertTail(node **head, int x)
{
    if (x < 0 || arr[x] == 1)
        return;
    node *p = makeNode(x);
    arr[x] = 1;
    cnt++;
    if (*head == NULL)
    {
        *head = p;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = p;

    return;
}

void Print_0(node *head)
{
    if (head == NULL)
        return;
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    return;
}

void Print_1(node *head)
{
    int *A = (int *)malloc(cnt * sizeof(int));
    int i = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            A[i] = temp->data;
            i++;
        }
        temp = temp->next;
    }
    while (head != NULL)
    {
        if (head->data % 2 != 0)
        {
            A[i] = head->data;
            i++;
        }
        head = head->next;
    }
    for (int i = 0; i < cnt; i++)
        printf("%d ", A[i]);
}

int main()
{
    node *head = NULL;

    return 0;
}