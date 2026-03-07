#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int value;
    struct node *next;
} node;

node *makenode(int x)
{
    node *p = (node *)malloc(sizeof(node));
    p->value = x;
    p->next = NULL;
    return p;
}

void print(node *head)
{
    if (head == NULL)
        return;
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    return;
}

int check_value(node *head, int x)
{
    if (x < 0)
        return 0;
    if (head == NULL)
        return 1;
    while (head != NULL)
    {
        if (head->value == x)
            return 0;
        head = head->next;
    }
    return 1;
}

void InsertHead(node **head, int x)
{
    if (check_value(*head, x))
    {
        node *p = makenode(x);
        p->next = *head;
        *head = p;
    }
    return;
}

void InsertTail(node **head, int x)
{
    if (check_value(*head, x))
    {
        node *p = makenode(x);
        node *q = *head;
        if (*head == NULL)
        {
            *head = p;
            return;
        }
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
    return;
}

void _free(node **head)
{
    node *p = *head;
    while (*head != NULL)
    {
        p = *head;
        (*head) = (*head)->next;
        free(p);
    }
}

int main()
{
    node *head = NULL;
    char status[10] = "";
    int data = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     InsertHead(&head, i);
    // }
    // for (int i = 100; i < 110; i++)
    // {
    //     InsertTail(&head, i);
    // }
    // InsertHead(&head, -100);
    // print(head);
    while (scanf("%s", status) != -1)
    {
        scanf("%d", &data);
        if (strcmp(status, "InsertHead") == 0)
        {
            InsertHead(&head, data);
        }
        else if (strcmp(status, "InsertTail") == 0)
        {
            InsertTail(&head, data);
        }
        else if (strcmp(status, "print") == 0)
        {
            if (data == 0)
            {
                print(head);
            }
        }
    }
    while (scanf("%s", status) != EOF)
    {
        scanf("%d", &data);
        if (strcmp(status, "InsertHead") == 0)
        {
            InsertHead(&head, data);
        }
        else if (strcmp(status, "InsertTail") == 0)
        {
            InsertTail(&head, data);
        }
        else if (strcmp(status, "print") == 0)
        {
            if (data == 0)
            {
                print(head);
                break;
            }
        }
    }
    return 0;
}