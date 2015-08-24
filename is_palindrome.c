#include<stdio.h>
#include<stdlib.h>

int palindrome (char *);

void main(void)
{
    int i,result;
    char input[25];
    printf("enter the input string\n");
    scanf("%[^\n]s",input);
    result=palindrome(input);
    if(result==0)
        printf("the string is not a palindrome");
    else
        printf("the string is palindrome ");
}

int palindrome(char *input)
{
    int length,i;
    for(length=0;input[length];length++);
    for(i=0;i<=length/2;i++)
        if(input[i]!=input[length-1-i])
            return 0;
    return 1;
}
