#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
const int BAR_LENGTH=50;
const int MAX_TASKS=5;
typedef struct
{
	int id,progress,step;
	
}Task;
void clear_screen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clr");
	#endif
}
void printbar(Task task)
{
	int bars_to_show=(task.progress*BAR_LENGTH)/100;
	printf("Task %d: [",task.id);
	int i;
	for(i=0;i<BAR_LENGTH;i++)
	{
		if(i<bars_to_show)
		{
			printf("=");
		}
		else
		{
			printf(" ");
		}
	}
		printf("] %d%%\n",task.progress);//double percentile for printing percentage
}
void main()
{
	srand(time(NULL));
Task tasks[MAX_TASKS];
int i;
for(i=0;i<=MAX_TASKS;i++)
{
	tasks[i].id=i+1;
	tasks[i].progress=0;
	tasks[i].step=rand() % 5 +1;
}
int tasks_incomplete=1;
while(tasks_incomplete)
{
	tasks_incomplete=0;
	clear_screen();
	int i=0;
	for(i=0;i<MAX_TASKS;i++)
	{
		tasks[i].progress+=tasks[i].step;
		if(tasks[i].progress>100)
		{
			tasks[i].progress=100;
		}
		else if(tasks[i].progress<100)
		{
			tasks_incomplete=1;
		}
		printbar(tasks[i]);
	}
	sleep(1);//sleep for 1 sec
}
printf("All task completed ");
}
