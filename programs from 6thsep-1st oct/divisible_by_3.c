//to find if the given number is divisible by 3 or not
#include<stdio.h>
#include<stdlib.h>

int divisible(char *,int );
int validation_check(char *);

void main(void)
{
	int result,k,IsValid;
	char p[50], *q;
	printf("enter the number (p)\n");
	gets(p);
	printf("enter the number of times to repeat the number p");
	scanf_s("%d", &k);
	if(validation_check(p))
		result = divisible(p, k);
	else
	{
		printf("the enterd number has invalid characters ");
		getch();
		exit(0);
	}
	for (;k > 0;k--)
		printf("%s", p);
	if (result == 1)
		printf(" is divisible by 3");
	else
		printf(" is not divisible by 3");
	getch();
}
int divisible(char *p, int k)
{
	int result = 0, i, sum=0;
	for (i = 0;p[i];i++)
		sum += (p[i] - '0');
	if (sum % 3 == 0 || k % 3 == 0)
		return 1;
	return 0;
}
int validation_check(char *p)
{
	int i;
	for (i = 0;p[i];i++)
		if (p[i]<'0' || p[i]>'9')
			return 0;
	return 1;
}