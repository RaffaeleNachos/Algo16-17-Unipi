#include <stdio.h>
#include <stdlib.h>

void reset(int array[], int len)
{
    int i;
    for (i=0; i<len; i++){
        array[i]=0;
    }
}

int main ()
{
    int i;
    int *contatore=malloc(10*sizeof(int));
    reset(contatore,10);
    int val;
    scanf("%d", &val);
    while(val!=-1){
        contatore[val]+=1;
        scanf("%d", &val);
    }
    for(i=0; i<10; i++){
        printf("%d\n", contatore[i]);
    }
    return 0;
}
