#include<stdio.h>
#include<conio.h>

int permutation_in_first(char *,char *);

void main(void)
{
    int i,j,k,result;
    char first[20],second[20];
    printf("enter the first string\n");
    scanf("%s",first);
    printf("enter the second string\n");
    scanf("%s",second);
    result= permutation_in_first(first,second);
    if(result==0)
        printf("false");

    else
        printf("true");
}
int permutation_in_first(char *first,char *second)
 {
    int i,j,len,flen=0;
    int alpha[256]={0};
    for(len=0;second[len];len++);
    for(flen=0;first[flen];flen++);
    if(flen!=len)
        return 0;
    for(i=0;first[i];i++)
        alpha[first[i]]++;
    for(i=0;second[i];i++)
        alpha[second[i]]--;
    for(i=0;i<256;i++)
        if(alpha[i]!=0)
            return 0;
    return 1;
 }
