//to find the x*y using bitwise operators only
#include<stdio.h>
#include<stdlib.h>

 int product_by_bitwise(int x, int y);

void main(void)
{
	unsigned int x, y;
	int k;
	printf("enter the values of x and y\t");
	scanf_s("%d%d", &x, &y);
	k = product_by_bitwise(x, y);
	printf("the value of %d*%d is %d", x, y, k);
	getch();
}
int product_by_bitwise(int x, int y)
{
	unsigned int result = 0;
	int flag=0;
	if(x < 0 && y<0)
	{
		y=(-1)*y;
		flag=1;
	}
	if(y<0)
	{
		y=(-1)*y;
		flag=1;
	}		
	for (;y != 0;y = y >> 1)
	{
		if (y & 1)
			result += x;
		x = x << 1;
	}
	if(flag==0)
		return result;
	else 
		return (-1)*result;
}