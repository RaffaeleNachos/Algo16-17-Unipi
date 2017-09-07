#include <stdio.h>
#include <stdlib.h>

char* product(char *str, int k)
{
    int i=0;
    char *strf;
    strf=malloc(1001*sizeof(char));
    int x;
    int j=0;
    for(i=0; i<k; i++){
        x=0;
        while(str[x]!=0){
            strf[j]=str[x];
            j++;
            x++;
        }
    }
    return strf;
}

int main ()
{
    int k;
    char *str;
    str=malloc(1001*sizeof(char));
    scanf("%s", str);
    scanf("%d", &k);
    printf("%s\n", product(str, k));
    return 0;
}
