#include<stdio.h>
#include<stdlib.h>

void read(int *,int N);
void sort1(int *, int N);
void sort2(int *, int N);
void sort3(int *, int N);
void swap(int *, int, int);


void main(void)
{
	int input[100], N,i;
	printf("enter the number of elements\n");
	scanf_s("%d", &N);
	if (N <= 0)
	{
		printf("enter a valid value");
		exit(0);
	}
	read(input, N);
	sort2(input, N);
	for (i = 0;i < N;i++)
		printf("%d ", input[i]);
	_getch();
}
void read(int *input, int N)
{
	int i;
	printf("enter the elements\t");
	for (i = 0;i < N;i++)
		scanf_s("%d", &input[i]);
}
void sort1(int *input, int N)
{
	//counting the number of zeros 
	int zeros=0, i;
	for (i = 0;i < N;i++)
		if (input[i] == 0)
			zeros++;
	for (i = 0;i < zeros;i++)
		input[i] = 0;
	for (i = zeros;i < N;i++)
		input[i] = 1;
}
void sort2(int *input, int N)
{
	//swapping the elements when found the zeros and one out of order
	int i=0, j=N-1;
	while (i > j)
	{
		if (input[i] == 0)
			i++;
		if (input[j] == 1)
			j--;
		if (input[i] != 0 && input[j] != 1)
			swap(input, i, j);
	}
}
void swap(int *input, int a, int b)
{
	//input[b] = (input[a] + input[b]) - (input[a] = input[b]);
	int temp;
	temp = input[a];
	input[a] = input[b];
	input[b] = temp;
}
void sort3(int *input, int N)
{

}