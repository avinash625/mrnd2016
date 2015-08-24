#include<stdio.h>
#include<stdlib.h>

void common(int *,char *,char *);
int isresult(char ch);

void main(void)
{
    char first[10],second[10],ch;
    int characters[256]={0};
    printf("enter the string\n");
    scanf("%s",first);
    printf("enter the second string\n");
    scanf("%s",second);
    printf("the common characters are \t");
    common(characters,first,second);
}
void common(int *characters,char *first,char *second)
{
    int i,j,k;
    char ch;
    for(i=0;(ch=first[i]);i++)
    {

        characters[ch]=1;
    }
    for(i=0;(ch=second[i]);i++)
    {
        if(characters[ch]==1)
        {
            printf("%c\t",ch);
            characters[ch]=0;
        }
    }
}



















