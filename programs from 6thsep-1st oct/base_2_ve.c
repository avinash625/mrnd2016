#include<stdio.h>
#include<stdlib.h>
void get_base_ve_2(int n, char *result);

void main(void)
{
	int n;
	char result[50];
	printf("enter the  number:");
	scanf_s("%d", &n);
	get_base_ve_2(n, result);
	printf("the equivalent of the given number in base -2 is %s", result);
	getch();
}
void get_base_ve_2(int n, char *result)
{
	int temp, i = 0, carry = 0, j;
	char ch;
	result[0] = '0';
	result[1] = '\0';
	while (n != 0)
	{
		result[i] = ((n % 2) ^ carry) + '0';
		if (!(n & 1))
		{
			carry = 0;
		}
		i++;
		if ((!(i & 1)) && (n & 1))
		{
			carry = 1;
		}
		n /= 2;
	}
	if (carry)
	{
		if ((i & 1))
		{
			result[i] = '1';
			i++;
		}
		result[i] = '1';
		i++;
	}
	result[i] = '\0';
	for (i = i - 1, j = 0;i > j;i--, j++)
	{
		ch = result[i];
		result[i] = result[j];
		result[j] = ch;
	}
}