#include<stdio.h>												

int start(int year);											//to declare additional function

int date_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};																				//to declare total of days in each months
const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};	//to declare name of months
const char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};																				//to declare name of days

int year;														//to save value of year that we input

int start_day(int year)											//this function is used to determine january 1st with use year that input from main function
{
	int day; 
	day=(year+((year-1)/4)-((year-1)/100)+((year-1)/400))%7;	//formula to know when january 1st
	return day;
}


int main()														//main function 
{
	int m, d, i, j;												//declare variable (m to call month, d to call day, i to looping for rows, j to looping for column(week)
	int shift, start;											//declare variable (shift set date in first row and continue, start to save where to start date in each months
	
	printf("Enter Year = ");	scanf("%d",&year);				//to input year what you want
	printf("\n\n");
	
	start = start_day(year);									// save value from start_day() function and save to variable start (just for determine start date in january)
	
	if(year%4 == 0 && year%100 !=0 || year%400 == 0)			//to determine year that we input, is it leap year?
		{
			date_month[1]=29;									//if the year is leap year, total days in february will be changed become 29 days
			
			printf("\t\t\tThis Year is Leap Year\n\n\n");		//to print word "This Year is Leap Year"
		}
	
	if(year>=1990)												//if the year more than equals to 1990, the program will print calender
	{
		for(m=0; m<12; m++)										//looping to call array months[]
		{						
			printf("\t\t\t\t%s %d\n",months[m],year);			//to print months in year

			for(d=0; d<7; d++)									//looping to call array days[]
			{
				printf("\t%s",days[d]);							//to print days in each months
			}
		
			printf("\n");		
		
			for(i=0; i<=5; i++)									//looping for rows in month
			{
				if(i==0)										//to set first day in month
				{
					for(j=0; j<start; j++)						//to empth the column suitable with previously month
					{
						printf("\t");
					}
				
					for(j=1; j<=7-start; j++)					//to set date in first row
					{
						printf("\t%d",j);						//print date in first row
					}
					shift=j;									//to save the last date that shown in first row

				}
			
				else
				{
					for(j=shift; j<7+shift; j++)				//to set date starting date in second row and the next rows
					{
						if(j<=date_month[m])					//match the date value with the number of days in the month displayed
						{
							printf("\t%d",j);					//print date in second row and the next rows
						}
					}
					shift=j;									//to save the last date and affect first date in the next rows

				}
				printf("\n");
			}
		
			start = (start + date_month[m])%7;					//to save the last day and affect starting day in the next month
		
			printf("\n");
		}
	}
	
	else 														//if the input of year less than 1990, the program will print "The Year is Wrong"
	{
		printf("The Year is Wrong");
	}
	
}




