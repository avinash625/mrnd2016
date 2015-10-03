#include<stdio.h>
#include<stdlib.h>
int validation_check(char *);
int addition(char *, char *);

void main(void)
{
	char first[50], second[50];
	printf("enter the first number\n");
	gets(first);
	printf("enter the second number\n");
	gets(second);
	if (validation_check(first) && validation_check(second))
		 addition(first, second);
	else
	{
		printf("the enterd numbers has invalid charaters");
		getch();
		exit(0);
	}
	printf("the sum of the 2 given numbers is %s", first);
	getch();
}
int validation_check(char *p)
{
	int i;
	for (i = 0;p[i];i++)
		if (p[i]<'0' || p[i]>'9')
			return 0;
	return 1;
}
int addition(char *first, char *second)
{
	int i, flag = 1, flag1 = 0, j = 0;
	for (i = 0; first[i];)
	{
		if (flag == 1)
		{
			if (first[i] - '0' + (second[i] - '0') > 9)
			{
				flag = 0;
				flag1 = 1;
				first[i] = (first[i] - '0') + (second[i] - '0');
				first[i]=(first[i] % 10) +48;
				continue;
			}
			else if (first[i] - '0' + second[i] - '0' == 9)
			{
				first[i] = (first[i] - '0' + second[i] - '0') + 48;
			}
			else if (first[i] - '0' + second[i] - '0' < 9)
				first[i] = (first[i] - '0' + second[i] - '0') + 48;
			i++;
		}
		if (flag == 0)
		{
			if (flag1 == 1)
			{
				flag1 = 0;
				j = i - 1;
			}
			if (first[j] == '9')
			{
				first[j] = '0';
				j--;
			}
			else if (first[j] < '9')
			{
				first[j]++;
				flag = 1;
				i++;
			}
		}
	}
	return 0;
}