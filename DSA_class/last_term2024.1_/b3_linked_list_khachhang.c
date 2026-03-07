#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GOLD "GOLD"
#define VIP "VIP"

typedef struct Customer
{
    char id[8];
    char name[21];
    char level[7];
    struct Customer *next;
} Customer;

typedef struct Customer node;

node *makeNode(char *id, char *name, char *level)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
        return NULL;
    strcpy(p->id, id);
    strcpy(p->name, name);
    strcpy(p->level, level);
    p->next = NULL;
    return p;
}

void Insert(node **head, char *id, char *name, char *level)
{
    node *newNode = makeNode(id, name, level);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void Print(node *head)
{
    if (head == NULL)
    {
        printf("EMPTY\n");
        return;
    }
    while (head != NULL)
    {
        printf("%s %s %s\n", head->id, head->name, head->level);
        head = head->next;
    }
}

void Vip(node **head)
{
    if (head == NULL || *head == NULL)
        return;
    node dummy;
    dummy.next = *head;
    node *prv = &dummy;
    node *cur = *head;
    while (cur != NULL)
    {
        if (strcmp(cur->level, VIP) == 0)
        {
            node *tmp = cur;
            prv->next = cur->next;
            cur = cur->next;
            free(tmp);
        }
        else
        {
            prv = cur;
            cur = cur->next;
        }
    }
    *head = dummy.next;
}

void Gold(node *head)
{
    int cnt = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->level, GOLD) == 0)
        {
            cnt++;
        }
        temp = temp->next;
    }
    if (cnt == 0)
        printf("NO GOLD\n");
    else
        printf("%d\n", cnt);
}

void Serve(node **head)
{
    if (head == NULL || *head == NULL)
        return;
    node *p = *head;
    *head = (*head)->next;
    free(p);
}

int main()
{
    node *head = NULL;
    char input[256];

    while (fgets(input, sizeof(input), stdin))
    {
        input[strcspn(input, "\r\n")] = 0;
        if (strcmp(input, "#") == 0)
            break;

        char *cmd = strtok(input, " ");
        if (cmd == NULL)
            continue;

        if (strcmp(cmd, "Create") == 0)
        {
            while (head != NULL)
                Serve(&head);
        }
        else if (strcmp(cmd, "Insert") == 0)
        {
            char *id = strtok(NULL, " ");
            char *name = strtok(NULL, " ");
            char *level = strtok(NULL, " ");
            if (id && name && level)
                Insert(&head, id, name, level);
        }
        else if (strcmp(cmd, "Print") == 0)
        {
            Print(head);
        }
        else if (strcmp(cmd, "Vip") == 0)
        {
            Vip(&head);
        }
        else if (strcmp(cmd, "Gold") == 0)
        {
            Gold(head);
        }
        else if (strcmp(cmd, "Serve") == 0)
        {
            Serve(&head);
        }
    }

    while (head != NULL)
        Serve(&head);
    return 0;
}