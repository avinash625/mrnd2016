#include<stdio.h>
#include<stdlib.h>
void get_base8(char *base2, char *base8);

void main(void)
{
	char base2[20], base8[20];
	printf("enter the base2 string");
	gets(base2);
	get_base8(base2, base8);
	printf("the equivalent of the given base 2 is %s", base8);
	fflush(stdin);
	getch();
}
void get_base8(char *base2, char *base8)
{
	int result, i, j, lengtha, lengthb;
	for (lengtha = 0;base2[lengtha];lengtha++);
	if (lengtha % 3 == 0)
	{
		lengthb = lengtha / 3 - 1;
		base8[lengthb+1] = '\0';
	}
	else
	{
		lengthb = lengtha / 3;
		base8[lengthb + 1] = '\0';
	}
	
	for (i = lengtha - 3;i  >= 0;i = i - 3)
	{
		if (base2[i] == '0')
		{
			if (base2[i+1] == '0'  && base2[i + 2] == '0')
				base8[lengthb] = '0';
			else if (base2[i+1] == '0'  && base2[i + 2] == '1')
				base8[lengthb] = '1';
			else if (base2[i+1] == '1'  && base2[i + 2] == '0')
				base8[lengthb] = '2';
			else
				base8[lengthb] = '3';
		}
		else
		{
			if (base2[i+1] == '0'  && base2[i + 2] == '0')
				base8[lengthb] = '4';
			else if (base2[i+1] == '0'  && base2[i + 2] == '1')
				base8[lengthb] = '5';
			else if (base2[i+1] == '1'  && base2[i + 2] == '0')
				base8[lengthb] = '6';
			else
				base8[lengthb] = '7';
			
		}
		lengthb--;
	}
	i = lengtha % 3;
	if (i == 1 && base2[i - 1] == '0')
		base8[lengthb] = '0';
	else if(i==1 )
		base8[lengthb] = '1';
	if (i == 2)
	{
		if (base2[i - 2] == '0' && base2[i - 1] == '0')
			base8[lengthb] = '0';
		else if (base2[i - 2] == '0' && base2[i - 1] == '1')
			base8[lengthb] = '1';
		else if (base2[i - 2] == '1' && base2[i - 1] == '0')
			base8[lengthb] = '2';
		else
			base8[lengthb] = '3';
	}
}