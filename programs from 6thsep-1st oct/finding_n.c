#include<stdio.h>
#include<stdlib.h>

int find_n(int *);

void main(void)
{
	int a[100], result, i, n;
	printf("enter the number of elements");
	scanf_s("%d", &n);
	if (n < 0)
	{
		printf("enter a correct number\n");
		getch();
		exit(0);
	}
	else
	{
		printf("enter the elements\n");
		for (i = 0;i < 2 * n + 2;i++)
		{
			scanf_s("%d", &a[i]);
		}
		result = find_n(a);
	}
	printf("the number of elements in the array is %d", result);
	getch();
}
int find_n(int *a)
{
	int temp, i = 1;
	if (a[0] > a[1])
		return 0;
	else if (a[0]<a[1] && a[1]>a[2])
		return 1;
	else if (a[1]<a[2] && a[2]>a[3])
		return 2;
	while(1)
	{
		if (a[i*2]!=0 && a[i+1]<a[i+2])
		{
				i = i * 2;
		}
		else
			break;
	}
	temp = i;
	while (1)
	{
		if (a[i + temp / 2] < a[i + temp / 2 + 1])
			i = i + temp / 2;
		else if (a[i + temp / 2]>a[i + temp / 2 + 1])
		{
			i = i + temp / 2;
			break;
		}
		else if (temp == 0)
			break;
		temp = temp / 2;
	}
	return i;
}