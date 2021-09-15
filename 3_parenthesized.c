//A C program to check whether a expression is correctly paranthesized or not.                 
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char str[100];
    int i=0, j, chk, count;
    printf("Enter Expression: ");
    gets(str); //This will read the expression entered by user.
    while(str[i]!='\0')
    {
        chk=0;
        if(str[i]=='('||str[i]==')'||str[i]=='{'||str[i]=='}'||str[i]=='['||str[i]==']')
        {
          //This will count the number of times a Parenthesis id entered.
          count++;
        }
       i++;
    }
    if(count%2==0)
      //Common sense **Logic: If a parenthesis is opened then it is needed to be closed, Thus there would be two parenthesis in a pair, So, even number of parenthesis makes a expression valid!...
      printf("\nExpression is Valid!");
    else
      printf("\nExpression is Invalid!");
    exit(0);
    return 0;
}
