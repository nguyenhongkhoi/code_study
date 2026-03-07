#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
        cnt++;
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\ncnt = %d\n",cnt);
    return;
}
void pushFront(node **head,int x){
    node *p = makenode(x);
    p->next = *head;
    *head = p;
    return;
}

void pushBack(node **head,int x){
    node *p = makenode(x);
    if(*head == NULL) {
        *head = p;
        return;
    }
    node *tmp = *head;
    while(tmp->next != NULL) tmp = tmp->next;
    tmp->next = p;
    return;
}

void insertBefore(node **head,int k,int x){
    node *p = makenode(x);
    if(*head == NULL) return;
    node *cur = *head;   

    if(cur->data == k) { //them o dau
        p->next = *head;
        *head = p;
    }

    while(cur->next != NULL){
        if(cur->next->data == k){
            node *p = makenode(x);
            p->next = cur->next;
            cur->next = p;
            cur = cur->next->next;
        }
        else{
            cur = cur->next;
        }
    }
    return;
}

void removeHead(node **head){
    if(*head == NULL) return;
    node *cur = *head;
    *head = (*head)->next;
    free(cur);
    return;
}
void removeTail(node **head){
    if(*head == NULL) return;
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    node *cur = *head;
    while(cur->next->next != NULL) cur = cur->next;
    free(cur->next);
    cur->next = NULL;
    return;
}

void remove(node **head, int x){
    if(*head == NULL) return;
    node dummy;
    dummy.next = *head;
    node *prev = &dummy;
    node *cur = *head;
    while(cur != NULL){
        if(cur->data == x){
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
        }else{
            prev = cur;
            cur = cur->next;
        }
    }
    *head = dummy.next;
}
void reverse(node **head){

    return;
}

void printReverse(node *head){
    if(head == NULL) return;
    if(head->next != NULL) printReverse(head->next);
    printf("%d ",head->data);
    return;
}




int main(){
    node *list = NULL;
    for(int i = 0; i<= 10;i++) pushBack(&list,i);
    insertBefore(&list, 2, 2);
    remove(&list,0);
    show(list);
    printReverse(list);
    return 0;
}