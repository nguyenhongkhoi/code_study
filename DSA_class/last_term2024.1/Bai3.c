#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer
{
    char id[8];
    char name[21];
    char level[7];
    struct customer *next;
} customer;

customer *Create()
{
    return NULL;
}

// Hàm bổ sung để giải phóng bộ nhớ khi gọi lệnh Create hoặc thoát
void ClearList(customer **head)
{
    while (*head != NULL)
    {
        customer *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

customer *makenode(char *x, char *y, char *z)
{
    customer *p = (customer *)malloc(sizeof(customer));
    strcpy(p->id, x);
    strcpy(p->name, y);
    strcpy(p->level, z);
    p->next = NULL;
    return p;
}

void insert(customer **head, char *x, char *y, char *z)
{
    customer *p = makenode(x, y, z);
    if (*head == NULL)
    {
        *head = p;
        return;
    }
    customer *cur = *head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = p;
}

void Print(customer *head)
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

void Vip(customer **head)
{
    if (*head == NULL)
        return;
    customer dmy;
    dmy.next = *head;
    customer *prev = &dmy, *cur = *head;

    while (cur != NULL)
    {
        if (strcmp(cur->level, "VIP") == 0)
        {
            customer *tmp = cur;
            prev->next = cur->next;
            cur = cur->next;
            free(tmp);
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    *head = dmy.next;
}

void Gold(customer *head)
{
    int check = 0;
    customer *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->level, "GOLD") == 0)
        {
            check++;
        }
        temp = temp->next;
    }
    if (check != 0)
    {
        printf("%d\n", check);
    }
    else
        printf("NO GOLD\n");
}

void Serve(customer **head)
{
    if (*head == NULL)
        return;
    customer *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

int main()
{
    customer *head = Create();
    char status[20];
    char x[10], y[30], z[15];

    while (scanf("%s", status) != EOF)
    {
        if (strcmp(status, "#") == 0)
            break;

        if (strcmp(status, "Create") == 0)
        {
            ClearList(&head);
            head = Create();
        }
        else if (strcmp(status, "Insert") == 0)
        {
            scanf("%s %s %s", x, y, z);
            insert(&head, x, y, z);
        }
        else if (strcmp(status, "Print") == 0)
        {
            Print(head);
        }
        else if (strcmp(status, "Vip") == 0)
        {
            Vip(&head);
        }
        else if (strcmp(status, "Gold") == 0)
        {
            Gold(head);
        }
        else if (strcmp(status, "Serve") == 0)
        {
            Serve(&head);
        }
    }

    ClearList(&head);
    return 0;
}
