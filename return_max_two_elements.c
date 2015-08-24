#include<stdio.h>
#include<stdlib.h>

void first2max(int *,int ,int *,int *);

void main(void)
{
    int n,first,second=-32767,* input;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    first2max(input,n,&first,&second);
    printf("the first max is %d and second max is %d",first,second);
}
void first2max(int *input,int n,int *first,int *second)
{
    int i;
    if(n==0 || n==1)
        printf("not to many elements to compare");
    else if(n==2)
    {
        input=(int *)malloc(n*sizeof(int));
        if(input==NULL)
        {
            printf("error occured ");
            exit(0);
        }
        else
        {
            printf("enter the numbers\n");
            scanf("%d%d",&input[0],&input[1]);
            if(input[0]>input[1])
            {
                *first=input[0];
                *second=input[1];
            }
            else
            {
                *second=input[0];
                *first=input[1];
            }
        }
    }
    else if(n>2)
    {
        int i,flag=0;
        input=(int *)malloc(n*sizeof(int));
        if(input==NULL)
        {
            printf("error occured ");
            exit(0);
        }
        else
        {
            printf("enter the numbers");
            for(i=0;i<n;i++)
                scanf("%d",&input[i]);
            *first=*second= input[0];
            for(i=0;i<n;i++)
            {

                if(input[i]>*first)
                {
                    *second=*first;
                    *first=input[i];
                }
                else if(*second==*first && input[i]<*first)
                {
                    *second=input[i];
                }
                else if(input[i]!=*first && (flag==1) && input[i]>*second)
                    *second=input[i];

            }

        }
    }
}

























