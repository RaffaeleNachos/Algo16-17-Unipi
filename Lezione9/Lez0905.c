#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node_struct {
    int key;
    struct ll_node_struct *left;
    struct ll_node_struct *right;
    struct ll_node_struct *center;
} ll_node;

ll_node* inserisci(ll_node *t, int key){
    //se l'albero é vuoto
    if(t==NULL){
        ll_node* new=(ll_node *)malloc(sizeof(ll_node));
        new->key=key;
        new->left=NULL;
        new->right=NULL;
        new->center=NULL;
        return new;
    }
    //se l'albero non é vuoto
    if(t->key>key)
        t->left=inserisci(t->left,key);
    else if(key%(t->key)==0)
        t->center=inserisci(t->center,key);
    else
        t->right=inserisci(t->right,key);
    return t;
}

int three(ll_node *t){
    //se t é vuoto
    if(t==NULL) return 0;
    //se é nel primo nodo
    if(t->left!=NULL && t->right!=NULL && t->center!=NULL){
        return 1+three(t->left)+three(t->right)+three(t->center);
    }
    return three(t->left)+three(t->right)+three(t->center);
}

int main ()
{
    int i;
    int n;
    int key;
    scanf("%d", &n);
    ll_node *root=NULL;
    for (i=0; i<n; i++){
        scanf("%d", &key);
        root=inserisci(root,key);
    }
    printf("%d\n", three(root));
    return 0;
}
