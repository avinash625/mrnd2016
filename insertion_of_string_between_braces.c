#include<stdio.h>
#include<stdlib.h>

int is_valid(char *input);
void insertion_of_text(char *braces,char *text);
void main(void)
{
    int i,result;
    char braces[40],text[20];
    printf("enter the first string(braces)\n");
    scanf("%s",braces);
    result=is_valid(braces);
    if(result==1)
    {
        printf("enter the text to be inserted in the string pattern\n");fflush(stdin);
        scanf("%[^\n]s",text);
        insertion_of_text(braces,text);
        printf("the text after inserting it in the pattern is %s",braces);
    }
    else
        printf("the entered braces pattern is not in order");
}
int is_valid(char *braces)
{
    int i,length;
    for(length=0;braces[length]!='\0';length++);
    if(length%2 == 1)
        return 0;
    for(i=0;i<length/2;i++)
    {
        if(braces[i]=='[' && braces[length-1-i]==']')
            continue;
        else if(braces[i]=='{' && braces[length-1-i]=='}')
            continue;
        else if(braces[i]=='(' && braces[length-1-i]==')')
            continue;
        else if(braces[i]=='<' && braces[length-1-i]=='>')
            continue;
        else
            return 0;
    }
        return 1;
}
void insertion_of_text(char *braces,char *text)
{
    int blen,tlen,j,k,temp;
    char ch;
    for(blen=0;braces[blen];blen++);
    for(tlen=0;text[tlen];tlen++);
    for(j=blen/2,k=0;text[k]!='\0' ; j++,k++)
    {
        ch=braces[j];
        braces[j]=text[k];
        text[k]=ch;
    }
    if(k<blen/2)
    {
        for(;braces[j];k++,j++)
            text[k]=braces[j];
    }
    for(k=0,j=blen/2+tlen;k<blen/2;k++,j++)
    {
        braces[j]=text[k];
    }
    braces[j]='\0';
}
