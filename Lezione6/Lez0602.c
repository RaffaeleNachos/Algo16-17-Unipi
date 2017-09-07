#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparechar (const void *a, const void *b)
{
    char **a1= (char**)a;
    char **b1= (char**)b;
    return -strcmp(*a1,*b1);
}

int main ()
{
    int dim;
    int i;
    char **a;
    scanf("%d", &dim);
    a=malloc(dim*sizeof(char*));
    for (i=0; i<dim; i++){
        a[i]=malloc(101*sizeof(char));
        scanf("%s", a[i]);
    }
    qsort(a,dim,sizeof(char*),comparechar);
    for (i=0; i<dim; i++){
        printf("%s\n", a[i]);
    }
    return 0;
}
