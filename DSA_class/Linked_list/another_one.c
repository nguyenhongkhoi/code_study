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

void pushFront(node **head,int x){
    node *newNode=makeNode(x);
    newNode->next = *head; //*head la dia chi cua not head trong dslk
    *head = newNode;


}
void pushback(node **head,int x){
    node *newNode = makeNode(x);
    node *temp = *head;
    if(temp == NULL) {*head = newNode; return;}
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;

}

void check(node *head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;

    }
    printf("\n");

}

int cnt(node *head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;

    }
    return cnt;
}

int main(){
    node *first = makeNode(6),
    *second = makeNode(9), *third  = makeNode(20);

    first->next = second;
    second->next = third;
    check(first);
    printf("cnt = %d\n",cnt(first));

    node *head = NULL;
    for(int i=1;i < 10;i++){
        pushFront(&head,i);

    }
    pushback(&head,100);
    check(head);
    printf("cnt = %d\n",cnt(head));
    return 0;
}