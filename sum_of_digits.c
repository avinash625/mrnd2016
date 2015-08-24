//finding the sum of the digits
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int sumof(int n);

void main(void)
{
    int n,i,result;
    printf("enter the value of the number\t:");
    scanf("%d",&n);
    result=sumof(n);
    printf("the sum of the digits of the given number is %d",result);
}
int sumof(int n)
{
    int result=0,i;
    if(n>=0)
    {
        while(n>0)
        {
            result+=n%10;
            n=n/10;
        }
    }
    else
    {
        result = (-1)*sumof((-1)*n);
    }
    return result;
}
