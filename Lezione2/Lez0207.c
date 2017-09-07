#include <stdio.h>
#include <stdlib.h>

char *my_strcat1(char *s1, char *s2)
{
    int i;
    int j;
    int conta=0;
    while(s1[conta]!=0){
        conta=conta+1;
    }
    j=0;
    for(i=conta; s2[j]!=0; i++){
        s1[i]=s2[j];
        j++;
    }
    return s1;
}

int main ()
{
    char *s1;
    char *s2;
    s1=malloc(1001*sizeof(char));
    s2=malloc(1001*sizeof(char));
    scanf("%s", s1);
    scanf("%s", s2);
    my_strcat1(s1,s2);
    printf("%s\n", s1);
    return 0;
}
