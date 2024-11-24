#include<stdio.h>
#define MAX_USERS 10
#define CERDENTIAL_LENGTH 30
#include<string.h>
typedef struct{
	char username[CERDENTIAL_LENGTH];
	char password[CERDENTIAL_LENGTH];
}User;
User users[MAX_USERS];
int users_count=0;
void register_user()
{
	if(users_count==MAX_USERS)
	{
		printf("Maximun %d users are supported , no more registrations are allowed \n",MAX_USERS);
		return;
	}
	int newindex=users_count;
	printf("\nRegister a new User name");
	printf("\nEnter username : ");
	fgets(users[newindex].username,CERDENTIAL_LENGTH,stdin);
	fixfgetsinput(users[newindex].username);
	input_password(users[newindex].password);
	users_count++;
	printf("\nRegistration successful");
}
void input_password(char * password)
{
	printf("Enter password : \n");
	fgets(password,CERDENTIAL_LENGTH,stdin);
	fixfgetsinput(password);
}
void fixfgetsinput(char * string)
{
	int index=strcspn(string,"\n");
	string[index]='\0';
}
int login_user()//returns user index
{
	char username[CERDENTIAL_LENGTH],password[CERDENTIAL_LENGTH];
	printf("Enter username\n");
	fgets(username,CERDENTIAL_LENGTH,stdin);
	fixfgetsinput(username);
	input_password(password);
	int i;
	for(i=0;i<users_count;i++)
	{
		if(strcmp(username,users[i].username)==0 && strcmp(password,users[i].password)==0)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int userindex;
	int option;
	while(1){
	
	printf("\nWelcome to User Management ");
	printf("\n1.Register");
	printf("\n2.Login");
	printf("\n3.Exit");
	printf("\nSelect an option : ");
	scanf("%d",&option);
	getchar();
	switch(option)
	{
		case 1:
			register_user();
			break;
		case 2:
			userindex=login_user();
			if(userindex>=0)
			{
				printf("Login successful welcome %s",users[userindex].username);
			}
			else
			{
				printf("Login failed incorrect user name or password \n");
			}
			break;
		case 3:
			printf("\nExiting program.");
			return 0;
			break;
		default:
			printf("Invalid option please try again ");
			break;
	}
}
return 0;
}
