#include<stdio.h>
#include<stdlib.h>

void reversing(char *);
void reverse(char *,int ,int);
void main(void)
{
    char input[50];
    printf("enter the string\n");
    scanf("%[^\n]s",input);
    reversing(input);
    printf("the strinng after reversing the words in the sentence is \n %s",input);
}
void reversing(char *input)
{
    int first=0,flag=0;
    char buffer;
    int i,j,k=0;
    for(i=0;input[i];i++);
    i--;
    for(;k<=i/2;k++)
    {
        buffer=input[i-k];
        input[i-k]=input[k];
        input[k]=buffer;
    }
    first=0;
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]==' '){
            reverse(input,first,i-1);
            first=i+1;
        }
    }

}
void reverse(char *input,int first,int last)
{
    char buffer;

    for(;first<last;first++,last--)
    {
        buffer=input[first];
        input[first]=input[last];
        input[last]=buffer;
    }
}
