#include<stdio.h>
#include<stdlib.h>
int modulo(int, int, int);

void main(void)
{
	unsigned int x, y, a;
	int result;
	printf("enter the values of x,y and z\t");
	scnaf_s("%d%d%d", &x, &y, &a);
	result = modulo(x, y, a);
	printf("the result is %d", result);
}
int modulo(int x, int y, int a)
{
	int i;
	if (x == a)
		return 0;
	else if (y == 0)
		return 1;
	for (i = 0;i < y;i++)
		x *= x;
	return x%a;
}