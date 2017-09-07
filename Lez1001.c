#include <stdio.h>
#include <stdlib.h>
#define primo 999149

typedef struct ll_node_struct {
    struct ll_node_struct* next;
    int info;
} ll_node;

void inserisci (ll_node *head, int v)
{
    ll_node *el = malloc(sizeof(ll_node));
    el->info=v;
    el->next=head;
    head=el;
}

int hash(int x, int a, int b, int n)
{
    int ris;
    ris=(((a*x)+b)%primo)%(2*n);
    return ris;
}

int main ()
{
    int i;
    int n;
    int key;
    int a;
    int b;
    int tot_conf=0;
    int max=0;
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);
    ll_node* tab=malloc((2*n)*sizeof(ll_node*));
    int *freq=malloc((2*n)*sizeof(int));
    for(i=0; i<2*n; i++){
        freq[i]=0;
    }
    for(i=0; i<n; i++){
        scanf("%d", &key);
        inserisci(&tab[hash(key,a,b,n)],key);
        if (freq[hash(key,a,b,n)]!=0) tot_conf++;
        freq[hash(key,a,b,n)]++;
    }
    for (i=0; i<2*n; i++){
        if (freq[i]>max) max=freq[i];
    }
    printf("%d\n", max);
    printf("%d\n", tot_conf);
    return 0;
}
