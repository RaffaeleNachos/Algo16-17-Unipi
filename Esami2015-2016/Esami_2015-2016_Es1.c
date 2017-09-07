#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ll_node_struct {
	int val;
	char *key;
	struct ll_node_struct *left;
	struct ll_node_struct *right; 
} ll_node;

ll_node* inserisci(ll_node *t, int val, char * string){
    //se l'albero é vuoto
    if(t==NULL){
        ll_node* new=(ll_node *)malloc(sizeof(ll_node));
		new->key=malloc(101*sizeof(char));
		strcpy(new->key,string);
        new->val=val;
        new->left=NULL;
        new->right=NULL;
        return new;
    }
    //se l'albero non é vuoto
    if(t->val<val)
        t->right=inserisci(t->right,val,string);
    else
        t->left=inserisci(t->left,val,string);
    return t;
}

int find_max(ll_node *u, int x)
{
	ll_node *corr=u;
	while(corr->right!=NULL){
		corr=corr->right;
	}
	printf("%d\n", corr->val);
	return 0;
}

ll_node* return_node_three(ll_node *u, char *str)
{
	ll_node* found=NULL;
	if (u==NULL) return NULL;	
	if (strcmp(u->key,str)==0) {
		//printf("trovato\n");
		find_max(u,0);
		return u;
	}
	//printf("vado a sx\n");
	found=return_node_three(u->left,str);
	//printf("vado a dx\n");
	found=return_node_three(u->right,str);
	return NULL;
}

int main ()
{
	int n,i;
	char *str=malloc(101*sizeof(char));
	scanf("%d", &n);
	ll_node *root=NULL;
	ll_node *temp=malloc(sizeof(ll_node));
	temp->key=malloc(101*sizeof(char));
	for (i=0; i<n; i++){
		scanf("%s", temp->key);
		scanf("%d", &temp->val);
		root=inserisci(root,temp->val,temp->key);
	}
	scanf("%s", str);
	return_node_three(root,str);
	return 0;
}
