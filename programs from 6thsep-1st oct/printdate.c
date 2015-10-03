#include<stdio.h>
#include<stdlib.h>

int is_valid_date(int day, int month, int year);
void date_in_words(int day, int month, int year,char day_no[][20], char months[][10], char one_to_ninetenn[][10], char tens[][10]);
void print_day(int day, char day_no[][10]);
void print_year(int year, char one_to_nineteen[][10], char tens[][10]);
void getdate(char *, int *, int *, int *);

void main(void)
{
	char months[][10] = { "","January","February","March","April","May","June","July","August","September","October","November","December" };
	char day_no[][10] = { "","first","second","third","fourth","fifth","sixth","seventh","eighth","ninth","tenth","eleventh","twelveth","thirteen","fourteenth","fifteenth","sixteenth","seventeenth","eighteenth","nineteenth" };
	char one_to_nineteen[][10] = { "","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
	char tens[][10] = { "","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
	char input_string[13];
	int day=0, month=0, year=0, result=0;
	printf("enter the date(day-month-year)\t");
	gets(input_string);
	getdate(input_string, &day, &month, &year);
	result = is_valid_date(day, month, year);
	if (result == 1)
	{
		
		date_in_words(day, month, year,day_no, months, one_to_nineteen, tens);
	}
	else
		printf("incorrect date");
	getchar();
}
//checks if the entered date is a valid date or not returns 1 if true
int is_valid_date(int day, int month, int year)
{
	if (month <= 0 || month >= 13)
		return 0;
	else if (month == 2)
	{
		if (year % 400 == 0 && day <30 && day >0)
			return 1;
		else if (year % 100 == 0 && day <= 28 && day>0)
			return 1;
		else if (year % 4 == 0 && year % 100 != 0 && day<30 && day >0)
			return 1;
		else if (year % 4 != 0 && day<29 && day>0)
			return 1;
		else
			return 0;
	}
	else if (month = 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day <= 0 || day >= 32)
			return 0;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day <= 0 || day >= 31)
			return 0;
	}
	return 1;
}
//function which calls the necessary functions to print the complete date
void date_in_words(int day, int month, int year,char day_no[][20], char months[][10], char one_to_nineteen[][10], char tens[][10])
{
	print_day(day, day_no);
	printf("%s\t", months[month]);
	print_year(year, one_to_nineteen, tens);
}
//to print the day
void print_day(int day, char day_no[][10])
{
	if (day <= 19)
		printf("%s\t", day_no[day]);
	else if (day <= 29)
	{
		printf("twenty");
		printf("%s\t", day_no[day % 20]);
	}
	else
	{
		if (day == 30)
			printf("thirty\t");
		else
			printf("thirtyone\t");
	}
}
//prints the year
void print_year(int year, char one_to_nineteen[][10], char tens[][10])
{
	if (year > 1000 && (year / 100 == 00 || year / 100 == 10 || year / 100 == 20 || year / 100 == 30 || year / 100 == 40 || year / 100 == 50 || year / 100 == 60 || year / 100 == 70 || year / 100 == 80 || year / 100 == 90))
	{
		printf("%s thousand  ", one_to_nineteen[year / 1000]);
		year = year % 100;
	}
	else
	{
		if (year / 1000 > 1)
			printf("%s%s ", tens[(year / 1000) - 1], one_to_nineteen[(year / 100) % 10]);
		else
			printf("%s ", one_to_nineteen[year / 100]);
		year = year % 100;
	}
	if (year < 1000 && (year / 10 == 00 || year / 10 == 1 || year / 10 == 2 || year / 10 == 3 || year / 10 == 4 || year / 10 == 5 || year / 10 == 6 || year / 10 == 7 || year / 10 == 8 || year / 10 == 9))
	{
		printf("%s ", tens[(year / 10) - 1]);
	}
	printf("%s ", one_to_nineteen[year % 10]);
}
void getdate(char *input_string, int *day, int *month, int *year)
{
	int i, d = 1,k;	
	for (i = 0;input_string[i] != '/';i++)
	{
		*day = (*day * 10) + (input_string[i] - '0');
	}
	for (i = i + 1;input_string[i] != '/';i++)
	{
		*month = (*month * 10) + (input_string[i] - '0');
	}
	for (i = i+1;input_string[i] != '\0';i++)
	{
		*year = (*year * 10) + (input_string[i] - '0');
	}
}