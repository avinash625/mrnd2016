#include<stdio.h>
#include<conio.h>

#include<stdlib.h>


void insert(int *,int value,int );
int main(void) {
	int n, i, value;
	int input[20];
	printf("enter the number of elements in the array\t");
	scanf("%d", &n);
	if (n < 0)
		printf("enter a correct number(-ve number is not valid)\n");
	else {
		printf("enter the values of array\t");
		for (i = 0;i < n;i++)
			scanf("%d", &input[i]);

		printf("enter the value to be inserted\t");
		scanf("%d", &value);
		insert(input,value,n);
		printf("the values are ");
		for (i = 0;i <= n;i++)
			printf("%d  ", input[i]);

	}
}
void insert(int *input,int value,int n ) {
	int i,k,temp;


		for (i = 0;input[i] < value;i++);k=i;
		temp=input[i];
		for(k=n;k>i;k--)
			input[k]=input[k-1];
		input[k]=value;


}
