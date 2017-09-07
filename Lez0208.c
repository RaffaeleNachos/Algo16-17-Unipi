#include <stdio.h>
#include <stdlib.h>

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i]!=0)
    {
        if(s2[i]==0) return 0;
        else if( s1[i]<s2[i]) return -1;
        else if( s1[i]>s2[i] ) return 1;
        i++;
    }
    return 0;
}

int main ()
{
    char *s1;
    s1=malloc(1001*sizeof(char));
    char *s2;
    s2=malloc(1001*sizeof(char));
    scanf("%s", s1);
    scanf("%s", s2);
    if(my_strcmp(s1,s2)==1) printf("+1\n");
    if(my_strcmp(s1,s2)==-1) printf("-1\n");
    if(my_strcmp(s1,s2)==0) printf("0\n");
    return 0;
}