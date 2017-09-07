#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node_struct {
	int info;
	struct ll_node_struct *next;
} ll_node;

ll_node* inserisci (ll_node *head, int v)
{
    ll_node *el = malloc(sizeof(ll_node));
    ll_node *corr=head;
    if (corr==NULL){
        el->info=v;
        el->next=NULL;
        corr=el;
        return el;
    }
    while (corr->next!=NULL){
        corr=corr->next;
    }
    corr->next=el;
    el->info=v;
    el->next=NULL;
    return head;
}

int sommasuffissa(ll_node *corr)
{
    if (corr==NULL) return 0;
    int tmp;
    int ris;
    ris=sommasuffissa(corr->next);
    tmp=corr->info;
    corr->info=ris;
    return ris+tmp;
}

void stampa(ll_node *head)
{
	ll_node *corr=head;
    while(corr!=NULL){
        printf("%d ", corr->info);
        corr=corr->next;
    }
}

int main ()
{
	int n;	
	int key;
	int i;
	scanf("%d", &n);
	ll_node *head=NULL;
	for (i=0; i<n; i++){
		scanf("%d", &key);
		head=inserisci(head,key);
	}
    ll_node *corr=head;
	stampa(head);
  	printf("\n");
	//fino a qui corretto
    sommasuffissa(corr);
	stampa(head);
	printf("\n");
	return 0;
}
