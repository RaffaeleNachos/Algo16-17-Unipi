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

void print(ll_node *t)
{
    if (t!=NULL){
        print(t->left);
        printf("%d\n", t->key);
        print(t->right);
    }
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
    print(root);
    return 0;
}
