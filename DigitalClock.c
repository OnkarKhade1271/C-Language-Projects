#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
void clear_screen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}
void fill_time(char * buffer , int format)
{
	time_t rawtime;
	struct tm *current_time;
	time(&rawtime);
	current_time=localtime(&rawtime);
	if(format==1)
	{
		strftime(buffer,50,"%H:%M:%S",current_time);
	}
	else
	{
		strftime(buffer,50,"%I:%M:%S %p",current_time);	
	}
	
}
void fill_date(char *buffer)
{
	time_t rawtime;
	struct tm *current_time;
	time(&rawtime);
	current_time=localtime(&rawtime);
	strftime(buffer,100,"%A %B %d %Y",current_time);	
}
void main()
{
char time[50], date[100];
int format;
printf("Choose the time format : ");
printf("\n1.24 hr format");
printf("\n2.12 hr format(default)");
printf("\nMake choice 1 or 2 : ");
scanf("%d",&format);
while(1)
{
fill_time(time,format);
fill_date(date);
clear_screen();
printf("Current time : %s \n",time);
printf("Date is %s ",date);	
sleep(1);//sleep for 1 sec 
}

}
