#include<stdio.h>
#include<stdlib.h>
int divisible1(char *,int );
int diff_sum(int);
void main(void)
{
	int result,k;
	char p[33];
	printf("enter the string p\n");
	gets(p);
	printf("enter the no of times to repeat the string p");
	scanf_s("%d", &k);
	result = divisible1(p, k);
	if (validation_check(p))
	{
		result = divisible1(p, k);
		if (result == 1)
			printf("the number enterd is divisible by 11");
		else
			printf("the number eneterd is not divisible by 11");
	}
	else
		printf("there are some invalid characters in the input");
	getch();
}
int divisible1(char *p, int k)
{
	int diff = 0, i, j, length, temp, counter;
	for (length = 0;p[length];length++);
	if (length == 3 && k % 2 == 0)
		return 1;
	else if (length % 2 == 0)
	{
		for (i = 0;p[i];i++)
			if (i % 2 == 0)
				diff += (p[i] - '0');
			else
				diff -= (p[i] - '0');
		if (diff*k >= 100)
			diff = diff_sum(diff*k);
		if (diff == 00 || diff == 11 || diff == 22 || diff == 33 || diff == 44 || diff == 55 || diff == 66 || diff == 77 || diff == 88 || diff == 99)
			return 1;
		else
			return 0;
	}
	else
	{
		for (i = 0, j = 0, counter = 0;j < k;counter++,i++)
		{
			if (counter % 2 == 0)
				diff += (p[i] - '0');
			else
				diff -= (p[i] - '0');
			if (i == length - 1)
			{
				j++;
				if (length == 1)
					i = -1;
				else
					i = 0;
			}	
		}
		if (diff >= 100)
			diff = diff_sum(diff);
		if (diff == 00 || diff == 11 || diff == 22 || diff == 33 || diff == 44 || diff == 55 || diff == 66 || diff == 77 || diff == 88 || diff == 99)
			return 1;
		else
			return 0;
	}
}
int diff_sum(int number)
{
	int difference = 0, counter = 0;
	while (number)
	{
		if (counter % 2 == 0)
			difference += number % 10;
		else
			difference -= number % 10;
		number = number / 10;
	}
	if (difference == 0 || difference == 11 || difference == -11)
		return 1;
	else if (difference <0 && difference >-11 || (difference>0 && difference < 11))
		return 0;
	else
		return diff_sum(difference);
}
int validation_check(char *p)
{
	int i;
	for (i = 0;p[i];i++)
		if (p[i]<'0' || p[i]>'9')
			return 0;
	return 1;
}