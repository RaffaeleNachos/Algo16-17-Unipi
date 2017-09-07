#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node_struct {
    int key;
    struct ll_node_struct *left;
    struct ll_node_struct *right;
} ll_node;

ll_node* inserisci(ll_node *t, int key){
    //se l'albero é vuoto
    if(t==NULL){
        ll_node* new=(ll_node *)malloc(sizeof(ll_node));
        new->key=key;
        new->left=NULL;
        new->right=NULL;
        return new;
    }
    //se l'albero non é vuoto
    if(t->key<key)
        t->right=inserisci(t->right,key);
    else
        t->left=inserisci(t->left,key);
    return t;
}

int percorso(ll_node *t1, ll_node *t2,int k){
    if(t1->key==k && t2->key==k) return 1;
    if(t1->key<k && t2->key<k && t1->key==t2->key)
        return percorso(t1->right,t2->right,k);
    if(t1->key>k && t2->key>k && t1->key==t2->key)
        return percorso(t1->left,t2->left,k);
    return 0;
}

int main ()
{
    int i;
    int n;
    int k;
    int key;
    scanf("%d %d", &n, &k);
    ll_node *root=NULL;
    ll_node *rootb=NULL;
    for (i=0; i<n; i++){
        scanf("%d", &key);
        root=inserisci(root,key);
    }
    for (i=0; i<n; i++){
        scanf("%d", &key);
        rootb=inserisci(rootb,key);
    }
    printf("%d\n", percorso(root,rootb,k));
    return 0;
}
