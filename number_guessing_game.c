#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int random_no,guess_no,no_of_guess=0;
    srand(time(NULL));//seeding because to stabalize the random no
    printf("Welcome to the world of guessing numbers : \n");
    random_no=rand() % 100 +1; //generating between 1 to 100  
   // printf("Number generted is %d ",random_no);
    do
    {
        printf("Please enter your guess between (1 to 100) : ");
        scanf("%d",&guess_no);
        no_of_guess++;
        if(guess_no < random_no)
        {
            printf("Guess larger number \n");
        }
        else if(guess_no > random_no )
        {
            printf("Guess smaller number \n");
        }
        else{
            printf("Congratulations ! You have successfully guessed the number !.... in %d attempts ",no_of_guess);
        }
    }while(guess_no!=random_no);
    printf("Thanks for playing \n");
    printf("Developed by Onkar Khade !......");
}