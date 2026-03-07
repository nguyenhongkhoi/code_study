#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0;

typedef struct node
{
    int data;
    struct node *next;
} node;

node *makenode(int x)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}

void pushHead(node **head, int x)
{
    node *p = makenode(x);
    p->next = *head;
    *head = p;
    return;
}

void pushBack(node **head, int x)
{
    node *p = makenode(x);
    if (*head == NULL)
    {
        *head = p;
        return;
    }
    node *tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = p;
    return;
}

void show(node *head1, node *head2)
{

    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            printf("%d ", head1->data);
            head1 = head1->next;
        }

        if (head2 != NULL)
        {
            printf("%d ", head2->data);
            head2 = head2->next;
        }
    }
    printf("\n");
}
int main()
{
    node *head1 = NULL, *head2 = NULL;
    char status[3] = " ";
    int a = 0, b = 0;
    scanf("%s", status);
    while (strcmp(status, "#") != 0)
    {
        if (strcmp(status, "I") == 0)
        {
            scanf("%d", &a);
            scanf("%d", &b);
            if (a == 1)
            {
                pushHead(&head1, b);
                cnt++;
            }
            else if (a == 2)
            {
                pushHead(&head2, b);
                cnt++;
            }
        }
        if (strcmp(status, "A") == 0)
        {
            scanf("%d", &a);
            scanf("%d", &b);
            if (a == 1)
            {
                pushBack(&head1, b);
                cnt++;
            }
            else if (a == 2)
            {
                pushBack(&head2, b);
                cnt++;
            }
        }

        scanf("%s", status);
    }
    show(head1, head2);

    return 0;
}
