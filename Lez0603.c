#include <stdio.h>
#include <stdlib.h>
typedef struct coordinate {
    int x;
    int y;
} coord;

int compareint (const void *a, const void *b)
{
    coord A=*(coord*)a;
    coord B=*(coord*)b;
    if (A.x==B.x && A.y>B.y) return -1;
    if (A.x==B.x && A.y<B.y) return 1;
    if (A.x<B.x) return -1;
    if (A.x>B.x) return 1;
    return 0;
}

int main ()
{
    int dim;
    int i;
    scanf("%d", &dim);
    coord *assi=malloc(dim*sizeof(coord));
    for (i=0; i<dim; i++){
        scanf("%d", &assi[i].x);
        scanf("%d", &assi[i].y);
    }
    qsort(assi,dim,sizeof(coord),compareint);
    for (i=0; i<dim; i++){
        printf("%d %d\n", assi[i].x, assi[i].y);
    }
    return 0;
}