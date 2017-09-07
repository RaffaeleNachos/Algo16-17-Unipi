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

int cerca(ll_node *t,int key){
    //se t é vuoto
    if(t==NULL) return -1;
    //se é nel primo nodo
    if(t->key == key) return 0;
    //utilizzo una variabile found che mi servirá per decretare se
    //l'elemento é presente (aumento di 1 e found diventa maggiore o uguale a 0) o no nell'albero
    int found = -1;
    if(t->key < key)
        found=cerca(t->right,key);
    else
        found=cerca(t->left,key);
    
    if(found >= 0) return 1+found;
    else return -1;
}

int main ()
{
    int i;
    int n;
    int key;
    int element;
    scanf("%d", &n);
    ll_node *root=NULL;
    for (i=0; i<n; i++){
        scanf("%d", &key);
        root=inserisci(root,key);
    }
    scanf("%d", &key);
    while(key!=-1){
        element=cerca(root,key);
        if (element==-1) printf("NO\n");
        else printf("%d\n", element);
        scanf("%d", &key);
    }
    return 0;
}
