#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[256];
    struct node *leftmostchild;
    struct node *rightsibling;
} node;

node *makeNode(char *name)
{
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->leftmostchild = NULL;
    temp->rightsibling = NULL;
    return temp;
}

node *find(node *head, char *name)
{
    if (head == NULL)
        return NULL;
    if (strcmp(head->name, name) == 0)
        return head;
    node *tmp = head->leftmostchild;
    while (tmp != NULL)
    {
        node *res = find(tmp, name);
        if (res != NULL)
            return res;
        tmp = tmp->rightsibling;
    }
}

int main()
{

    return 0;
}