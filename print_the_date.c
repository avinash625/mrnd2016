#include<stdio.h>
#include<stdlib.h>

int is_valid_date(int day,int month,int year);
void date_in_words(int day,int month,int year,char months[][10],char one_to_ninetenn[][10],char tens[][10]);
void print_day(int day,char one_to_nineteen[][10]);
void print_year(int year,char one_to_nineteen[][10],char tens[][10]);

void main(void)
{
    char months[][10]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
    char one_to_nineteen[][10]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char tens[][10]={"","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    int day,month,year,result,temp;
    printf("enter the date(day-month-year)\t");
    scanf("%d%d%d",&day,&month,&year);
    if(day<=0 || month<=0 || year<=0)
    {
        printf("incorrect date");
        exit(0);
    }
    result=is_valid_date(day,month,year);
    if(result==1)
    {
        date_in_words(day,month,year,months,one_to_nineteen,tens);
    }
    else
        printf("incorrect date");
}
//checks if the entered date is a valid date or not returns 1 if true
int is_valid_date(int day,int month,int year)
{
    int result;
    if(month<=0 || month>=13)
        return 0;
    else if(month==2)
    {
        if(year%400==0 && day <30 && day >0)
            return 1;
        else if(year%100==0 && day<=28 && day>0)
            return 1;
        else if(year%4==0 && year%100 != 0 && day<30 && day >0)
            return 1;
        else if(year%4!=0 && day<29 && day>0)
            return 1;
        else
            return 0;
    }
    else if(month=1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
    {
        if(day<=0 || day>=32)
            return 0;
    }
    else if(month==4||month==6||month==9||month==11)
    {
        if(day<=0 || day>=31)
            return 0;
    }
    return 1;
}
//function which calls the necessary functions to print the complete date
void date_in_words(int day,int month,int year,char months[][10],char one_to_nineteen[][10],char tens[][10])
{
    print_day(day,one_to_nineteen);
    printf("%s\t",months[month]);
    print_year(year,one_to_nineteen,tens);
}
//to print the day
void print_day(int day,char one_to_nineteen[][10])
{
    if(day<=19)
        printf("%s\t",one_to_nineteen[day]);
    else if(day<=29)
    {
        printf("twenty");
        printf("%s\t",one_to_nineteen[day%20]);
    }
    else
    {
        if(day==30)
            printf("thirty\t");
        else
            printf("thirtyone\t");
    }
}
//prints the year
void print_year(int year,char one_to_nineteen[][10],char tens[][10])
{
    if(year >=1000)
    {
        printf("%s thousand ",one_to_nineteen[year/1000]);
        if(year%1000==0)
            year=0;
        else
            year=year%1000;
    }
    else if(year<=999 && year>=100)
    {
        printf("%s hundred ",one_to_nineteen[year/100]);
        if(year%100==0)
            year=0;
        else
            year=year%100;
    }
    if(year<=99 && year>=20)
    {
        printf("%s ",tens[year/10]);
        if(year%10==0)
            year=0;
        else
            year=year%10;
    }
    else
        printf("%s",one_to_nineteen[year]);
}
