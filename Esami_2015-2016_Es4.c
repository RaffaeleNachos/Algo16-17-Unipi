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

int invisita(ll_node *root, int *contatore, int n)
{
	int found;	
	if (root==NULL) return 0;
	found=invisita(root->left, contatore, n);
	*contatore=*contatore+1;
	if ((n/2)+1==*contatore) {
		printf("%d\n", root->key);
	}
	found=invisita(root->right, contatore, n);
	return 0;
}

int main ()
{
    int i,n,key;
	int contatore=0;
    scanf("%d", &n);
    ll_node *root=NULL;
    for (i=0; i<n; i++){
        scanf("%d", &key);
        root=inserisci(root,key);
    }
	invisita(root,&contatore,n);
    return 0;
}