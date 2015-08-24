#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int greater(char *, char *);

void main(void)
{
    int i,j,temp,result;
    char first[10],second[10];
    printf("enter the first string(number)\t:");
    scanf("%s",first);
    if(first==NULL)
    {
        printf("enter the correct number\n");
        exit(0);
    }
    printf("enter the second string(number)\t:");
    scanf("%s",second);
    if(second==NULL)
    {
        printf("enter the correct number\n");
        exit(0);
    }
    result = greater(first,second);
    if(result==0)
        printf("the first number is greater");
    else if(result==1)
        printf("the second number is greater");
    else
        printf("the they both are equal");
}
int greater(char *first,char *second){

    int i,flag=0;
    int flen,slen,t1,t2;
    for(flen=0,i=0;first[flen];flen++)
        if(first[flen]!='0')
        {
            first[i]=first[flen];
            i++;
            flag=1;
        }
        else if(flag==1)
            i++;
        else
            continue;
    first[i]='\0';
    flag=0;
    for(slen=0,i=0;second[slen];slen++)
        if(second[slen]!='0')
        {
            second[i]=second[slen];
            i++;
            flag=1;
        }
        else if(flag==1)
            i++;
        else
            continue;
    second[i]='\0';
    for(flen=0;first[flen];flen++);
    for(slen=0;second[slen];slen++);
    t1=0;
    t2=0;
    if(flen==slen)
    {
        while(1)
        {
            if(first[t1]==second[t2])
            {
                if(t1==flen)
                    return 2;

            }
            else if(first[t1]>second[t2])
                return 0;
            else if(first[t1]<second[t2])
                return 1;
                t1++;
                t2++;
        }
    }
    else if(flen>slen)
        return 0;
    else
        return 1;
}
























