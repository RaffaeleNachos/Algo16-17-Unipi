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

int trova_media(ll_node *head)
{
	int tot=0;
	ll_node *corr=head;
	while (corr!=NULL){
		tot=tot+corr->info;
		corr=corr->next;
	}
	return tot;
}

ll_node *elimina_list(ll_node *head, int media)
{
	ll_node *corr=head;
	ll_node *prec=NULL;
	while (corr!=NULL){
        if (corr->info<=media && prec==NULL) {
            prec=corr;
            corr=corr->next;
            free(prec);
			prec=NULL;
			head=corr;
        }
		else if(corr->info<=media && prec!=NULL){
			prec->next=corr->next;
			free(corr);
			corr=NULL;
			corr=prec->next;
		}
        else{
			prec=corr;
			corr=corr->next;			
		}
	}
	return head;
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
	int media;
	int i;
	scanf("%d", &n);
	ll_node *head=NULL;
	
	for (i=0; i<n; i++){
		scanf("%d", &key);
		head=inserisci(head,key);
	}
	media=(trova_media(head)/n);
	printf("%d\n", media);
	stampa(head);
  	printf("\n");
	//fino a qui corretto 
	head=elimina_list(head,media);
	stampa(head);
	printf("\n");
	return 0;
}
