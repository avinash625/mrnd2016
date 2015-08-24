#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void rotate(int *, int ,int N);
void main(void)
{
	int input[20];
	int n,i,N;
	printf("enter no. of rotations\t");
	scanf("%d",&n);
	if(n<0)
	{
		printf("enter the correct number(-ve integer is not valid )");
		exit(0);
	}
	printf("enter N(no of elements in the array)\t");
	scanf("%d",&N);
	if(n<0)
		printf("enter a correct number");
	else
		rotate(input,n,N);
	printf("the array after the rotation\t");
	for(i=0;i<N;i++)
		printf("%d\t",input[i]);
}
void rotate(int *input,int n,int N)
{
	int i,k,j,temp;
	printf("enter the values of array\t");
	for(i=0;i<N;i++)
		scanf("%d",&input[i]);
	if(n%N==0 || n==0)
	{
		return;
	}
	else if(N==1)
	{
		return;
	}
	else if(k=n%N)
	{
		for(i=0;i<k;i++)
		{
			temp=input[N-1];
			for(j=N-1;j>0;j--)
			{
				input[j]=input[j-1];
			}
			input[0]=temp;
		}
	}
}
