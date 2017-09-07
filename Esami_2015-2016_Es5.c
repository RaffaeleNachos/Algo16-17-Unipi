#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node_struct {
	int info;
	struct ll_node_struct *next;
} ll_node;

ll_node* inserisci_in_testa(ll_node *head, int v)
{
    ll_node *el = malloc(sizeof(ll_node));
    el->info=v;
    el->next=head;
    head=el;
    return el;
}

int search (ll_node *head, int v)
{
    ll_node *corr=head;
    while(corr!=NULL){
        if (corr->info==v) return 1;
        else corr=corr->next;
    }
    return 0;
}

ll_node *movetofront(ll_node *head, int z)
{
	ll_node *corr=head;
	ll_node *prec=NULL;
    while (corr->info!=z){
        prec=corr;
        corr=corr->next;
    }
    if (prec!=NULL){
        prec->next=corr->next;
        corr->next=head;
        head=corr;
    }
	return head;
}

void print (ll_node *head)
{
    ll_node *el;
    el = head;
    while (el!=NULL) {
        printf("%d ", el->info);
        el=el->next;
    }
	printf("$\n");
}

ll_node *delete_last(ll_node *head)
{
	ll_node *corr=head;
	if (corr->next==NULL){
		head=NULL;
		return head;
	}
	while(corr->next->next!=NULL){
		corr=corr->next;
	}
	free(corr->next);
	corr->next=NULL;
	return head;
}

int main ()
{
	int n;
	int e;
	int tmp;
	int conta=0;
	scanf("%d", &n);
	ll_node *head=NULL;
	scanf("%d", &e);
	while(e!=0){
		if (e==1) {
			scanf("%d", &tmp);
			if(search(head,tmp)) head=movetofront(head,tmp);
			else{
				if (conta<n) {
					head=inserisci_in_testa(head, tmp);
					conta=conta+1;
				}
				else {
					head=delete_last(head);
					head=inserisci_in_testa(head, tmp);
				}
			}
		}
		if (e==2) {
			print(head);
		}		
		scanf("%d", &e);
	}
	return 0;
}