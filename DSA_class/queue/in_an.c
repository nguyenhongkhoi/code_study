#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data[100];
    struct node *next;
} node;

node *makeNode(char *data)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
        return NULL;
    strcpy(p->data, data);
    p->next = NULL;
    return p;
}

void push(node **head, node **tail, char *data)
{
    node *newNode = makeNode(data);
    if (*head == NULL)
    {
        *head = *tail = newNode;
        return;
    }
    (*tail)->next = newNode;
    *tail = newNode;
}

void popAndPrint(node **head, node **tail)
{
    if (*head == NULL)
    {
        printf("EMPTY\n");
        return;
    }
    printf("%s\n", (*head)->data);
    node *temp = *head;
    *head = (*head)->next;

    if (*head == NULL)
        *tail = NULL;

    free(temp);
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    char input[120];

    while (1)
    {
        if (fgets(input, sizeof(input), stdin) == NULL)
            break;
        input[strcspn(input, "\n")] = '\0';

        char *cmd = strtok(input, " ");
        if (cmd == NULL)
            continue;

        if (strcmp(cmd, "END") == 0)
        {
            break;
        }
        else if (strcmp(cmd, "PRINT") == 0)
        {
            popAndPrint(&head, &tail);
        }
        else if (strcmp(cmd, "ADD") == 0)
        {
            char *val = strtok(NULL, " ");
            if (val != NULL)
            {
                push(&head, &tail, val);
            }
        }
    }

    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}