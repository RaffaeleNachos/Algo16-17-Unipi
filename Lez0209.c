#include <stdio.h>
#include <stdlib.h>

char* my_strcpy(char* dest, char* src)
{
    int i=0;
    while(src[i]!=0){
        dest[i]=src[i];
        i++;
    }
    src[i]=0;
    return dest;
}

int main ()
{
    char *s1;
    s1=malloc(1001*sizeof(char));
    char *dest;
    dest=malloc(1001*sizeof(char));
    scanf("%s", s1);
    my_strcpy(dest,s1);
    printf("%s\n", dest);
    return 0;
}
