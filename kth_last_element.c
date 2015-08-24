#include<stdio.h>
#include<stdlib.h>


char getelement(char *input);


void main(void)
{
	char input[30],ch;
	int N;
	printf("enter the string\n");
	scanf("%s",input);
	ch=getelement(input);
	if(ch==-1)
		printf("k value greater than the size of the string");
	else if(ch== -2)
		printf("\0 is the character");
	else
		printf(" %c is the character ",ch);
	getchar();
}
char getelement(char *input)
{
	char *p,*q;
	int k,i,j;
	printf("enter the value of K\t");
	scanf("%d",&k);
	if(k<0)
	{
		printf("enter a correct value(-ve integer is not valid)");
		exit(0);
	}
	else
	{
		for(i=0;i<k;i++)
			if(input[i]=='\0')
				return -1;
		for(j=0;input[i]!='\0';j++,i++);
		if(input[i]=='\0')
			if(i==j)
			{
				printf("NULL character ");
				exit(0);
			}
			else
				return input[j];
	}
}
