#include<stdio.h>
#include<math.h>
double div(double n1,double n2)
{
if(n2==0){
printf("Invalid argument for Division\n");
exit(1);
}
else{
    return n1/n2;
}
}

int mod(int n1,int n2)
{
if(n2==0){
printf("Invalid argument for Modulus\n");
exit(1);
}
else{
    return n1%n2;
}
}
void main()
{
    int choice;
    double first,second,result;
    while(1){
    printf("\n Welcome to Simple Calculator \n ");
    printf("Choose one of the following options ....\n");
    printf("\n1. Adittion");
    printf("\n2. Subtraction");
    printf("\n3. Multiply");
    printf("\n4. Divide");
    printf("\n5. Modulus");
    printf("\n6. Power");
    printf("\n7. Exit");
    printf("\nNow enter your choice : ");
    scanf("%d",&choice);
    if(choice==7)
    {
        break;
    }
    if(choice <1 || choice >7)
    {
        printf("Invalid menu choice ...");
        continue;
    }
    printf("Please input the first number : \n");
    scanf("%lf",&first);
     printf("Please input the second number : \n");
    scanf("%lf",&second);
    switch(choice)
    {
        case 1:
        //Add
        result = first+second; 
        break;
        case 2:
        //Sub 
        result = first-second;
        break;
        case 3:
        //Mul 
        result = first*second;
        break;
        case 4: 
        //Div
        result = div(first,second);
        break;
        case 5: 
        //Mod
        result =mod(first,second);
        break;
        case 6: 
        //Pow
        result = pow(first,second);
        break;
    }
    printf("Result is %.2f  \n",result);
    }
    printf("Successful exit");

}
