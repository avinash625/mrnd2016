//adds the 2 numbers given in string format
#include<stdio.h>
#include<stdlib.h>

int addition(char *, char *);

void main(void)
{
	char first[50], second[50];
	int carry;
	printf("enter the first number\n");
	gets(first);
	printf("enter the second number\n");
	gets(second);
	if(validation_check(first) && validation_check(second))
			carry = addition(first, second);
	else
	{
		printf("the enterd numbers has invalid charaters");
		getch();
		exit(0);
	}
	printf("the sum of the 2 given numbers is %d%s", carry, first);
	getch();
}
int addition(char *first, char *second)
{
	char *temp;
	int carry = 0, flen, slen, i, j,fchar,schar;
	for (flen = 0;first[flen];flen++);
	for (slen = 0;second[slen];slen++);
	//making the largest number as first and swapping the values of flen and slen if necessary
	(flen > slen) ? (temp=first) : (temp = first, first = second, second = temp, flen ^= slen ^= flen ^= slen);
	for (i = flen - 1, j = slen - 1;j >= 0;i--,j--)//
	{
		fchar = first[i] - '0';
		schar = second[j] - '0';
		if (fchar + schar + carry >= 10)
		{
			first[i] = ((carry + fchar + schar) % 10) + '0';
			carry = 1;
		}
		else
		{
			first[i] = (fchar + schar) + '0';
			carry = 0;
		}
	}
	for (;i >= 0;i--)
	{
		fchar = first[i] - '0';
		if (carry == 1)
		{
			if (fchar + carry >= 10)
			{
				first[i] = ((fchar + carry) % 10) + '0';
				carry = 1;
			}
			else
			{
				carry = 0;
			}
		}
	}
	return carry;
}
int validation_check(char *p)
{
	int i;
	for (i = 0;p[i];i++)
		if (p[i]<'0' || p[i]>'9')
			return 0;
	return 1;
}