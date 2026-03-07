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

void show(node *top){
    int cnt  = 0;
    if(top == NULL) {printf("stack NULL\n"); return;}
    while(top != NULL) {
        printf("%d ",top->data);
        cnt++;
        top = top->next;
    }
    printf("\ncnt = %d\n",cnt);

}
void top(node *top){
    if(top == NULL) {printf("empty top\n"); return;}
    printf("%d\n",top->data);
    return;
}

void push(node **top, int x){
    node *p = makenode(x);
    p->next = *top;
    *top = p;
    return;
}
void pop(node **top){
    node *tmp = *top;
    if(*top == NULL) return;
    if((*top)->next == NULL){
        free(*top);
        *top = NULL;
        return;
    }
    *top = (*top)->next;
    free(tmp);
    return;

}
void insertBefore(node **top,int k, int x){
    //node *p = makenode(x);
    node dummy;
    dummy.next = *top;
    node *prev = &dummy;
    node *cur = *top;
    if(*top == NULL) {
        return;
    }
    while(cur != NULL){
        if(cur->data == k){
            node *p = makenode(x);
            prev->next = p;
            p->next = cur;
            prev = cur;
            cur = cur->next;
            
        }else{
            prev = cur;
            cur = cur->next;
        }
        
    }
    *top = dummy.next;
    
    
    return;
}
void remove(node **top, int x){
    if(*top == NULL) return;
    if((*top)->next == NULL){
        if((*top)->data == x){
            free(*top);
            *top = NULL;
            
        }
        return;
    }
    node dummy;
    dummy.next = *top;
    node *prev = &dummy;
    node *cur = *top;
    while(prev->next != NULL){
        if(prev->next->data == x){
            node *p = prev->next;
            prev->next = p->next;
            prev = prev->next->next; 
            free(p);
        }else{
            prev = prev->next;
        }
    }
    *top = dummy.next;
    return;
}


int main(){
    node *stack = NULL;
    for(int i = 0; i<=10; i++) push(&stack, i);
    show(stack);
    insertBefore(&stack, 5, 2000);
    remove(&stack,8);
    show(stack);
    // pop(&stack);
    // top(stack);
    // while(stack != NULL) {
    //     pop(&stack);
    //     top(stack);
    // }

    return 0;
}