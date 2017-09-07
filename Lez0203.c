#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *s)
{
    int i=0;
    int conta=0;
    while (s[i]!=0){
        conta=conta+1;
        s=s+1;
    }
    return conta;
}

int main(void) 
{
    char s[1001];
    scanf("%s", s);
    printf("%d\n", my_strlen(s));
    system("pause");
	return 0;
}
