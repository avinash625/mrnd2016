#include<stdio.h>
#include<stdlib.h>

int divisible(long int n);

void main(void)
{

    long int n,result;
    printf("enter the number \n");
    scanf("%ld",&n);
    result= divisible(n);

    if(result==0)
        printf("not divisible");
    else
        printf("divisible");
}
int divisible(long int n)
{
    int d,flag=1,sumofeven=0,sumofodd=0;
    if((n>1 && n<10))
        return 0;
    while(n!=0)
    {
        d=n%10;
        n=n/10;
        if(flag%2==0)
        {
            sumofeven+=d;
            flag++;
        }else
        {
            sumofodd+=d;
            flag++;
        }
    }
        if(sumofeven==sumofodd)
            return 1;
        else if(sumofeven>sumofodd)
            return divisible(sumofeven-sumofodd);
        else
            return divisible(sumofodd-sumofeven);

}
