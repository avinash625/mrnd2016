#include<stdio.h>
#include<stdlib.h>

void tuple(int *,int n,int sum);
int isresult(int a);
int result[10][2];
int k;
void main(void)
{
    int *input,n;
    int i,sum=0;
    printf("enter the number of elements\t");
    scanf("%d",&n);
    if(n>0)
    {
        input=(int *)malloc(n*sizeof(int));
        if(input==NULL)
        {
            printf("error occured");
            exit(0);
        }
	printf("enter the values of the arary elements\n");
        for(i=0;i<n;i++)
            scanf("%d",&input[i]);
    }
    else if(n<=0)
    {
        printf("enter correct number(-ve number is not valid)");
        exit(0);
    }
    printf("enter the value of the tuple\t");
    scanf("%d",&sum);
    tuple(input,n,sum);
    printf("the tuples are ");
    for(k=k-1;k>=0;k--)
    printf("{%d,%d} ",result[k][1],result[k][0]);
}
void tuple(int *input,int n,int sum)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {            if(input[i]+input[j]==sum && isresult(input[i]) && isresult(input[j]))
                {
                    result[k][0]=input[i];
                    result[k][1]=input[j];
                    k++;
                }
        }
    }
}
int isresult(int ch)
{
    int i;
    if(ch==0 )
        return 1;

    for(i=0;i<=k;i++)
        if((result[i][0]==ch || result[i][1]==ch) )
            return 0;
    return 1;
}

