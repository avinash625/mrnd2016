#include<stdio.h>
#include<stdlib.h>
void repeat(char *);
void  main(void)
{
    char input[20],ch;
    printf("enter the string\t");
    scanf("%s",input);
    repeat(input);
    getch();
}

void repeat(char *input)
{
    int i,j,length;
    char ch=input[0];
    int count=0;
    for(length=0;input[length];length++);
    for(i=0;i<length;i++)
    {
        if(input[i]==ch)

        {
            count++;
        }
        else if(input[i]!=ch && count==1)
        {
            count=0;
            ch=input[i];
        }
        else
        {
            count--;
        }
    }
    for(i=0;i<length;i++)
    {
        if(input[i]==ch)
            count++;
    }
    if(count>=length/2)
        printf("%c",ch);
}
