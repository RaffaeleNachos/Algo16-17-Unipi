#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int key; /* Chiave */
	struct _node* left; /* Sottoalbero sinistro */
	struct _node* right; /* Sottoalbero destro */
} ll_node ;

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

int print_2nd_max(ll_node *u)
{
	ll_node *corr=u;
	ll_node *prec=NULL;
	while (corr->right!=NULL){
		prec=corr;
		corr=corr->right;
	}
	if (corr->left==NULL && corr->right==NULL){
		printf("%d\n", prec->key);
		return 0;
	}
	if (corr->left!=NULL){
		corr=corr->left;
	}
	else {
		printf("%d\n", corr->key);
		return 0;
	}
	while (corr->right!=NULL){
		corr=corr->right;
	}
	printf("%d\n", corr->key);
	return 0;
}

int main ()
{
	int n;
	int val;
	int i;
	ll_node* root=NULL;
	scanf("%d", &n);
	for (i=0; i<n; i++){
		scanf("%d", &val);
		root=inserisci(root,val);
	}
	print_2nd_max(root);
	return 0;
}
