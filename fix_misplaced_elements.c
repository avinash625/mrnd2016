//to find out the misplaced elements in the array and to correct them
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void misplaced(int *,int n);
void read(int *,int n);
void swap(int *,int ,int);

void main(void)
{
    int n,i,input[20];
    printf("enter the number of elements in the array\t:");
    scanf("%d",&n);
    read(input,n);
    misplaced(input,n);
    printf("the array after the changing of the misplaced elements\t");
    for(i=0;i<n;i++)
       printf("%d ",input[i]);
}
void read(int *input,int n)
{
    int i;
    if(n<0)
    {
        printf("enter a correct value(-ve integer is not valid)");
        exit(0);
    }
    else if(n==0 || n==1)
    {
        printf("NO elements to be corrected");
        exit(0);
    }
    else
    {

            printf("enter the values of the array\t");
            for(i=0;i<n;i++)
                scanf("%d",&input[i]);
    }
}
void misplaced(int *input,int n)
{
    int i,m1,flag=0,redundant=0;//misplaced 1 and misplaced 2 variables
    if(n==2)
    {
        printf("assuming that the array is in sorted(ascending order)\n");
        if(input[0]>input[1])
        {
            swap(input,0,1);
        }
    }
    else if(n>2)
    {
       for(i=1;i<n;i++)
       {
            if(input[0]>input[1] && i==1)
            {
                m1=0;
                flag=1;
                if(n==3){
                    if(input[i+1]<input[m1] && n==3)
                        swap(input,m1,i+1);
//                    else if(input[i+1]<input[m1] && input[m1]<=input[i+2])
//                        swap(input,m1,i+1);
                    else if(input[i]<input[m1])//condition if the 2 elements are at the first 2 positions itself
                            swap(input,m1,i);}
                else if(input[m1]<input[i+1])        //condition to check if the 2 misplaced elements are in the first 2 positions
                    swap(input,m1,i);
                else if(input[m1]>input[i+1] && input[m1]<input[i+2])
                    swap(input,m1,i+1);
            }
            else if(input[i]==input[i+1] && redundant==0 &&  flag!=1)
            {
                if(i==1 && input[i-1]==input[i])//condition to check if the element is in the first position and along with redundant elements
                    m1=i-1;
                else
                    m1=i;
                redundant=1;
            }
            else if(input[i]<input[i+1] && redundant==1 && flag!=1)
            {
                m1=i;
                redundant=0;//removing the redundant flag if the next number is not equal.
            }
            else if(input[i]>input[i+1]&& flag==0)//condition to capture the first conflict(misplaced element )
            {

                flag=1;
                if(redundant!=1)
                    m1=i;
                if(i==n-2)
                    swap(input,m1,i+1);
                else if(input[i]>input[i+1])
                        if(input[i+1]<input[i+2])
                            swap(input,m1,i+1);

            }
            else if(flag==1)//condition to find the second conflict
            {
                if(i==n-1)
                {
                    if(input[m1]>input[i])
                    {
                        swap(input,m1,i);
                    }
                }
                else if(input[i]>input[i+1])
                    swap(input,m1,i+1);
            }
       }

    }
}
void swap(int *input,int a,int b)
{
    int temp;
    temp=input[a];
    input[a]=input[b];
    input[b]=temp;
}














