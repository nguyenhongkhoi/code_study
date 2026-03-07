#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

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

void push(node **top, int x){
    node *p = makenode(x);
    if(*top == NULL) {
        *top = p;
        return;
    }
    node *cur = *top;
    while(cur->next != NULL) cur = cur->next;
    cur->next = p;
    return;
}

void show(node *top){
    int cnt = 0;
    if(top == NULL){
        printf("queue NULL or empty\n");
        return;
    }
    while(top != NULL){
        printf("%d ", top->data);
        cnt++;
        top = top->next;
    }
    printf("\ncnt = %d\n",cnt);
    return;
}

void pop(node **top){
    if(*top == NULL) return;
    if((*top)->next == NULL){
        free(*top);
        *top = NULL;
        return;
    }
    node *tmp = *top;
    *top = (*top)->next;
    free(tmp);
    return;
}

void top(node *top){
    if(top == NULL){
        printf("queue NULL");
        return;
    }
    printf("%d\n", top->data);
    return;
    }



int main(){ 
    node *queue = NULL;
    for(int i = 0; i <= 10; i++) push(&queue,i);
    show(queue);
    pop(&queue);
    show(queue);
    top(queue);
    return 0;
}