#include <stdio.h>

int* FindVal(int a[], int len, int val)
{
    int i;
    for(i=0; i<len; i++){
        if (val==a[i]) return &a[i];
    }
    return NULL;
}

int main ()
{
    int array[10];
    int i;
    int val;
    for (i=0; i<10; i++){
        scanf("%d", &array[i]);
    }
    scanf("%d", &val);
    if (FindVal(array,10,val)!=NULL) printf("trovato\n");
    else printf("non trovato\n");
}
