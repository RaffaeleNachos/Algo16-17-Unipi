#include <stdio.h>
#include <stdlib.h>

int compareint (const void *a, const void *b)
{
    int A=*(int*)a;
    int B=*(int*)b;
    if (A%2==0 && B%2==0) return A - B;
    if (A%2!=0 && B%2!=0) return B - A;
    if (A%2==0 && B%2!=0) return -1;
    if (A%2!=0 && B%2==0) return 1;
    return 0;
}

int main ()
{
    int dim;
    int i;
    int *a;
    scanf("%d", &dim);
    a=malloc(dim*sizeof(int));
    for (i=0; i<dim; i++){
        scanf("%d", &a[i]);
    }
    qsort(a,dim,sizeof(int),compareint);
    for (i=0; i<dim; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}