//Name:Abhinesha Dhar                                                      
// Purpose ;  // Postfix Evaluatation
           // 1) Enter Expression
           // 2) Choose Operatation ( + , - , * , /)
           // 4) $$ Exit $$	
	#include<stdio.h> //   Pre-Processive to include standard input and output funtion header files
	
	int stack[20];  // Maximum size of Stack i.e 20
	int top = -1;  // stack is empty
	int n1,n2,n3,num; // Global Declratation
	void push(int x)
	{      // Pre-increment 
	    top=top+1;
	    stack[top]=x;
	}
	
	int pop()
{
    return stack[top--]; // Returns a reference to the top element in the stack.
}

	int main()
	{
	    char exp[20];
	    char *e;
	    printf("Welcome to Postfix Operations");
		printf("  Only enter in this e.g: abc+-*/  ");	
	    printf("Enter the expression in the postfix :: ");
	    scanf("%s",exp);
	    e = exp;
	    while(*e)             // *e means dereference the value stored at the location pointed by e
	    {
	        if(isdigit(*e))
	        {
	            num = *e -'0'; // In ASCII, '0' == 48, '1' == 49, and so on. Thus, '0' - 48 == 0, '1' - 48 == 1, and so on. That is, subtracting by 48 translates the char values '0'..'9' to the int values 0..9.
	            push(num);
	        }
	        else
	        {
	            n1 = pop();
	            n2 = pop();
	            switch(*e)
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
	        e++; // Post Increment  because it increments e's value by 1 after the operation is over.
	    }
	    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
	    return 0;
	
}