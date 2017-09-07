#include <stdio.h>
#include <stdlib.h>
int anagramma(unsigned char *s1, unsigned char *s2)
{
    int aS[256];
    int aZ[256];
    int i=0;
    for(i=0; i<256; i++){
        aS[i]=0;
        aZ[i]=0;
    }
    i=0;
    while(s1[i]!=0){
        aS[s1[i]]++;
        i++;
    }
    i=0;
    while(s2[i]!=0){
        aZ[s2[i]]++;
        i++;
    }
    i=0;
    while(i<256){
        if(aS[i]!=aZ[i]) return 0;
        i++;
    }
    return 1;
}

int main ()
{
    unsigned char *s1;
    s1=malloc(1001*sizeof(char));
    unsigned char *s2;
    s2=malloc(1001*sizeof(char));
    scanf("%s", s1);
    scanf("%s", s2);
    //anagramma(s1,s2);
    if(anagramma(s1,s2)==1) printf("1\n");
    if(anagramma(s1,s2)==0) printf("0\n");
    return 0;
}
