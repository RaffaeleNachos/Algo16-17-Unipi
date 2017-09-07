#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ll_node_struct{
	char *nome;
	struct ll_node_struct *next;
} ll_node;

int stringcomp(const void *p1, const void *p2)
       {
           return strcmp(*(char* const*)p1, *(char* const*)p2);
       }

ll_node* node_remove(ll_node *head)
{
	ll_node *corr=head;
	head=head->next;
	free(corr);
	corr->next=NULL;
	return head;
}

ll_node* inserisci(ll_node *head, char *v)
{	
	ll_node *new=malloc(sizeof(ll_node));
	new->nome=malloc(101*sizeof(char));
	strcpy(new->nome,v);
	new->next=NULL;
	if (head==NULL) {
		head=new;
		return head;
	}
	else{
	ll_node *corr=head;
	while(corr->next!=NULL){
		corr=corr->next;
	}
	corr->next=new;
	return head;
	}		
} 

void stampa(ll_node *head)
{
	ll_node *corr=head;
	while(corr!=NULL){
		printf("%s\n", corr->nome);
		corr=corr->next;
	}
}

int main ()
{
	ll_node *head=NULL;
	char *name=malloc(101*sizeof(char));
	int n;
	int i;
	int conta=0;
	scanf("%d", &n);
	while(n!=0){
		if(n==1){
			scanf("%s", name);
			head=inserisci(head,name);
			conta=conta+1;
		}
		if(n==2){
			head=node_remove(head);
			conta=conta-1;
		}
		scanf("%d", &n);
	}
	char **T=malloc(conta*sizeof(char*));
	for(i=0; i<conta; i++){
		T[i]=malloc(101*sizeof(char));
		strcpy(T[i],head->nome);
		head=node_remove(head);
	}
	qsort(T, conta, sizeof(char *), stringcomp);
	for(i=0; i<conta; i++){
		printf("%s\n", T[i]);
	}
	printf("$\n");
	return 0;	
}
