#include<stdio.h>
#include<conio.h>

int string_length(char *);

void main(void)
{
    int result=0;
    char input[50];
    printf("enter the input string\n");
    scanf("%[^\n]s",input);
    result=string_length(input);
    printf("the length of the string is %d",result);
}
int string_length(char *input)
{
    int i;
    for(i=0;input[i]!='\0';i++);
    return i;
}
