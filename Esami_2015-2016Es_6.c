#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node_struct {
	int key;
	int count;
	struct ll_node_struct *next;
} ll_node;

int search (ll_node *head, int v)
{
    ll_node *corr=head;
    while(corr!=NULL){
        if (corr->key==v) return 1;
        else corr=corr->next;
    }
    return 0;
}

ll_node* inserisci_in_testa(ll_node *head, int v)
{   
	ll_node *corr=head;
	if (search(head,v)) {
		while(corr->key!=v) corr=corr->next;
		corr->count=corr->count+1;
		return head;
	}
	else{
		ll_node *el = malloc(sizeof(ll_node));
		el->count=1;
    	el->key=v;
    	el->next=head;
    	head=el;
    	return el;
	}
}

int hash(int k, int n)
{
	int ris;
	ris=(k%n);
	return ris;
}

int main ()
{
	int k,n,i;	
	int *a;
	scanf("%d", &n);
	scanf("%d", &k);
	a=malloc(n*sizeof(int));
	ll_node **T;
	T=malloc(n*sizeof(ll_node*));
	for (i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for (i=0; i<n; i++){
		T[hash(a[i],n)]=inserisci_in_testa(T[hash(a[i],n)],a[i]);
	}
	for (i=0; i<n; i++){
		if (T[hash(a[i],n)]!=NULL && T[hash(a[i],n)]->count>=k) printf("%d ", a[i]);
	}
	printf("\n");	
}