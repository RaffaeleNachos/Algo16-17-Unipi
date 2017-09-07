#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct parola {
    char str[101];
    int dim;
} string;

int comparestr (const void *a, const void *b)
{
    string A=*(string*)a;
    string B=*(string*)b;
    if (A.dim==B.dim && strcmp(A.str,B.str)<0) return -1;
    if (A.dim==B.dim && strcmp(A.str,B.str)>0) return 1;
    if (A.dim<B.dim) return -1;
    if (A.dim>B.dim) return 1;
    return 0;
}

int main ()
{
    int dim;
    int i;
    scanf("%d", &dim);
    string *stringa=malloc(dim*sizeof(string));
    for (i=0; i<dim; i++){
        scanf("%s", stringa[i].str);
		  stringa[i].dim=strlen(stringa[i].str);
    }
    qsort(stringa,dim,sizeof(string),comparestr);
    for (i=0; i<dim; i++){
        printf("%s\n", stringa[i].str);
    }
    return 0;
}