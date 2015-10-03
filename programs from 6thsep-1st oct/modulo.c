#include<stdio.h>
#include<stdlib.h>

unsigned int modulo(int x, int y, int a);

void main(void)
{
	unsigned int x, a,result;
	int y;
	printf("enter the values of x,y and a\n");
	scanf_s("%d%d%d", &x, &y, &a);
	if (x < 0 || y < 0 || a <= 0)
	{
		printf("invalid number (enter the correct number)");
		getch();
		exit(0);
	}
	result = modulo(x, y, a);
	printf("the value of (%d power %d )modulo %d is  %d", x,y,a,result);
	fflush(stdin);
	getch();
}
unsigned int modulo(int x, int y, int a)
{
	unsigned int temp = 0, result = 0,flag=1;
	int i;
	if (y == 0 && a!=1)
		return 1;
	 temp = (((x%a)*(1%a)) % a);
	for (i = 1;i < sizeof(int) * 8;i++)
	{
		
		if (y & 1)
		{
			if (flag == 1 && i==1)
			{
				flag = 0;
				result = ((x %a)*(1%a)) % a;
			}
			else if (flag == 1)
			{
				flag = 0;
				result = ((temp%a)*(temp%a) % a);
			}
			else
				result = (((temp%a)*(result%a)) % a);
		}
		temp = (temp%a)*(temp%a) % a;
		y = y >> 1;
	}
	return result;
}