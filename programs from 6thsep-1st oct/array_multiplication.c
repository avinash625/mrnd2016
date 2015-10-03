#include<stdio.h>
#include<stdlib.h>

void multiplication(unsigned int *a,unsigned int *b,unsigned int result);

void main(void)
{
	unsigned int a[10] = { 0 }, b[5] = { 0 }, result[16] = { 0 };
	int  na, nb, i;
	printf("enter the number of elements in a\n");
	scanf_s("%d", &na);
	printf("enter the elements of a\n");
	for (i = 10 - na;i < 10;i++)
		scanf_s("%d", &a[i]);
	printf("enter the number of elemnts in b\n");
	scanf_s("%d", &nb);
	printf("enter the elements of b\n");
	for (i = 5 - nb;i < 5;i++)
		scanf_s("%d", &b[i]);
	multiplication(a, b, result);
	printf("the result of the a*b is ");
	for (i = 0;i < 15;i++)
		printf("%d ", result[i]);
	getch();
}
void multiplication(unsigned int *a, unsigned int *b, unsigned int *result)
{
	unsigned int carry = 0;
	unsigned long int temp, tempcarry;
	int i, j;
	for (i = 4;i >= 0;i--)
	{
		carry = 0;
		for (j = 9;j >= 0;j--)
		{

			tempcarry=temp = a[j] * b[i] + result[i + j + 1]+carry;
			result[i + j + 1] = temp & 0x00000000FFFFFFFF;
			carry = tempcarry & 0xFFFFFFFF00000000;
		}

	}
}