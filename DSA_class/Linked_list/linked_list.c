#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;

};

typedef struct node node;
node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;

}

void check(node *head){
    int cnt = 0;
    while(head != NULL){
        printf("%d ",head->data );
        cnt++;
        head = head->next;
    }
    printf("\ncnt = %d\n",cnt);
 }

void pushFront(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = *head;
    *head = newNode;
}

void pushBack(node **head, int x){
    node *newNode = makeNode(x);
    node *temp = *head;
    if(temp == NULL){
        *head = newNode;
        return;
    }
    while(temp->next != NULL) temp  = temp->next;
    temp->next = newNode;

}
void addFront(node **head,int x,int y){
    node *newNode = makeNode(y);
    node *temp = *head;
    if(temp->data == x){
        newNode->next = temp;
        temp = newNode;
    }
    while(temp->next->data != x && temp->next != NULL) temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    return;

}


int main(){
    node *first = makeNode(9),
    *second = makeNode(20), *third = makeNode(30);

    first->next = second;
    second->next = third;
   // pushFront(&first,100);
    pushBack(&first,200);
    addFront(&first,9,400);
    check(first);
   /* node *bobo = NULL;
    for(int i = 0;i <=10;i++) pushBack(&bobo,i);
    check(bobo);
    for(int i = 0;i <=10;i++) pushFront(&bobo,i);
    check(bobo);*/



    return 0;
}
