#include <stdio.h>
#include <stdlib.h>

char *my_strcat2(char *s1, char *s2, int dim1, int dim2)
{
    int i=dim1;
    int j=0;
    while (j<=dim2){
        s1[i]=s2[j];
        j++;
        i++;
    }
    return s1;
}

int main ()
{
    char *s1;
    char *s2;
    int dim1;
    int dim2;
    
    scanf("%d", &dim1);
    s1=malloc((dim1+1)*sizeof(char));
    scanf("%s", s1);
    
    scanf("%d", &dim2);
    s2=malloc((dim2+1)*sizeof(char));
    scanf("%s", s2);
    
    my_strcat2(s1,s2,dim1,dim2);
    
    printf("%s\n", s1);
    return 0;
}
