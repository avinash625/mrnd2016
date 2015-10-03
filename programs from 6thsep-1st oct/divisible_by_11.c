#include<stdio.h>
#include<stdlib.h>
 
int divisible2(char *s);
void main(void)
{
	char input[20];
	int result;
	printf("enter the input string\n");
	gets(input);
	if (validation_check(input))
		result = divisible2(input);
	else
	{
		printf("the enterd number has invalid characters\n");
		getch();
		exit(0);
	}
	if (result == 1)
		printf("the number eneterd is divisible by 11");
	else
		printf("the number entered is not divisible by 11");
	getch();
}
int divisible1(char *input)
{
	long int difference = 0;
	int i  ;
	for (i = 0;input[i];i++)
		if (i % 2 == 0)
			difference += (input[i] - '0');
		else
			difference -= (input[i] - '0');
	if (difference == 0 || difference == 11 || difference == -11)
		return 1;
	else if (difference > 0 && difference < 11 || (difference <0 && difference >-11))
		return 0;
	else
		return divisible_by_11(difference);
}
int divisible_by_11(long int number)//generic function that takes the number and finds that if it is divisible by 11
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
		return divisible_by_11(difference);
}
int validation_check(char *p)
{
	int i;
	for (i = 0;p[i];i++)
		if (p[i]<'0' || p[i]>'9')
			return 0;
	return 1;
}
int divisible2(char *input)
{
	int i, length, sum = 0, temp;
	for (length = 0;input[length];length++);
	for (i = length-1;i-1 >= 0;i = i - 2)
		sum += (((input[i - 1] - '0') * 10) + input[i] - '0');
	if (length%2==1)
		sum += (input[0] - '0');
	temp = sum;
	if (sum >= 100)
	{
		sum=div_num(temp);
	}
	if (sum == 00 || sum == 11 || sum == 22 || sum == 33 || sum == 44 || sum == 55 || sum == 66 || sum == 77 || sum == 88 || sum == 99)
	{
		return 1;
	}
	else
		return 0;
}
int div_num(int temp)
{
	int sum=0;
	while (temp)
	{
		sum += temp % 100;
		temp = temp / 100;
	}
	if (sum >= 100)
		return div_num(sum);
	else
		return sum;
}