#include<stdio.h>
#include<stdlib.h>

unsigned int modulo(int x, int y, int a);

void main(void)
{
	unsigned int x, y, a,result;
	printf("enter the values of x,y and a\n");
	scanf_s("%d%d%d", &x, &y, &a);
	result = modulo(x, y, a);
	printf("the value of (x power y )modulo a is  %d", result);
	getch();
}
unsigned int modulo(int x, int y, int a)
{
	unsigned int temp = 0, result = 0,flag=1;
	int i;
	 temp = (((x%a)*(1%a)) % a);
	y = y >> 1;
	for (i = 1;i < sizeof(int) * 8;i++)
	{
		
		if (y & 1)
		{
			if (flag == 1)
			{
				flag = 0;
				result = ((x %a)*(1%a)) % a;
			}
			else
				result = (((temp%a)*(result%a)) % a);
		}
		temp = (temp%a)*(temp%a) % a;
		y = y >> 1;
	}
	return result;
}