#include<stdio.h>
#include<stdlib.h>
int find_rank(int);
int factorial(int n);
void main(void)
{
	int rank,negative;
	int N;
	printf("enter the number\t");
	scanf_s("%d", &N);
	if (N < 0)
	{
		negative = 1;
		N += (2 * -N);
	}
	rank = find_rank(N);
	printf("the rank is %d", rank);
	_getch();
}
int find_rank(int N)
{
	int temp[10] = { 0 },result=0,perm=0;
	int tempnum=0,i=0,j,digits=0;
	while (N)
	{
		tempnum = N % 10;
		N = N / 10;
		digits++;
		temp[i] = tempnum;
		i++;
	}i--;
	for (j = 0;j <= i / 2;j++)
	{
		tempnum = temp[j];
		temp[j] = temp[i - j];
		temp[i - j] = tempnum;
	}
	for (i = 0;i < digits;i++)
	{
		perm = 0;
		for (j = i + 1;j < digits;j++)
		{
			if (temp[i] > temp[j])
				perm++;
		}
		result += (factorial(perm)*(digits - i - 1));
	}
	return result;

}
int factorial(int n)
{
	int i,perm=1;
	if (n == 0)
		return 0;
	for (i = 2;i <= n;i++)
		perm=perm*i;
	return perm;
}