//finding the nth fibonacci element in the sequence
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int fiboelement(int n);

void main(void)
{
    int n,result;
    printf("enter the value of n\t:");
    scanf("%d",&n);
    result=fiboelement(n);
    printf("considering that the indexes can start from 0\n");
    printf("the %dth element of the fibonacci series(0 1 1 2 3 5 8.......) is %d",n,result);
}
int fiboelement(int n)
{
    unsigned long int first=0,second=1,temp;
    int i;
    if(n<0)
    {
        printf("enter the correct number(-ve number is not valid)\n");
        exit(0);
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(n==0)
                return 0;
            else if(n==1)
                return 1;
            else
            {
                temp=second;
                second+=first;
                first=temp;
            }

        }
        return first;
    }
}
