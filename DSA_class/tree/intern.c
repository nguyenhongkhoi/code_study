#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[256];
    struct node *lmostchild;
    struct node *rsibling;    
}node;

node *makenode(char *name){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name,name);
    p->lmostchild = NULL;
    p->rsibling = NULL;
    return p;
}

node *findnode(node *root,char *name){
    if(root == NULL) return NULL;
    if(strcmp(root->name,name) == 0) return root;
    node *p  = root->lmostchild;
    while(p != NULL){
        node *q = findnode(p, name);
        if(q != NULL) return q;
        p = p->rsibling;
    }
    
}



int main(){
    node *root = NULL;




    return 0;
}
