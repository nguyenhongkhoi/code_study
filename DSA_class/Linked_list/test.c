#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
    int data;
    struct node *next;

}node;

node *makenode(int x){
    node *p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;

}

void show(node *head){
    int cnt = 0;
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
        cnt++;
    }
    printf("\ncnt = %d\n",cnt);
}

void pushFront(node **head,int x){
    node *p = makenode(x);
    p->next = *head;
    *head = p;
    return;
}

void pushBack(node **head,int x){
    node *p = makenode(x);
    node *tmp = *head;
    if(*head == NULL){
        *head = p;
        return;
    }
    while(tmp->next != NULL) tmp = tmp->next;
    tmp->next = p;
    return;
}

void removehead(node **head){
    if(*head == NULL) return;
    node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
    return;
}

void removetail(node **head){
    if(*head == NULL) return;
    if((*head)->next == NULL) { free(*head); *head = NULL; }
    node *tmp = *head;
    while(tmp->next->next != NULL) tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;

}
void remove(node **head, int x){
    if(*head == NULL) return;
    node dummy;
    dummy.next = *head;
    node *tmp = *head;
    node *prev = &dummy;
    while(tmp != NULL){
        if(tmp->data == x){
            prev->next = tmp->next;
            free(tmp);
            tmp = prev->next;
        }else{
        prev = tmp;
        tmp = tmp->next;
        }
    }
    *head = dummy.next;
}

int main(){
    node *list = NULL;
    for(int i = 0;i <= 10; i++){
        pushFront(&list,i);
    }
    for(int i = 0;i <= 10; i++){
        pushBack(&list,i);
    }
    removehead(&list);
    removetail(&list);
    remove(&list,9);
    show(list);

    return 0;
}