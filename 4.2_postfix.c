#include<stdio.h>  // Pre-Prossive To include standard input and output header files 
int pop(); // Funtion declratation 
	
	int stack[20];   // Stack size declared
	int top = -1;   // Checks the stack is overflow or not 
	int n1,n2,n3,num; // Global Declratation
	void push(int x)
	{      // Pre-increment 
	    top=top+1;
	    stack[top]=x;
	}
	
	int pop()
	{
	
    return stack[top--]; 
}
int main()
{
	 char Alpha[20];
	 char *a;
	 printf("Enter the expression in the postfix :: ");
	 scanf("%s",Alpha);
	 a = Alpha;
	while(*a)             
	{
	    if(isdigit(*a))
	     {
	        num = *a -'0'; 
	        push(num);
	     }
	    else
	    {
	        n1 = pop();
	        n2 = pop();
	        switch(*a)
	        {
	         case '+':
	         {
	            n3 = n1 + n2;
	            break;
	        }
	        case '-':
	        {
	         n3 = n2 - n1;
	         break;
	        }
	         case '*':
	            {
	                n3 = n1 * n2;
	                break;
	            }
	            case '/':
	            {
	                n3 = n2 / n1;
	                break;
	            }
	            }
	            push(n3);
	        }
	        a++;
	    }
	    printf("\nThe result of expression %s  =  %d\n\n",Alpha,pop());
	    return 0;
	}