#include<stdio.h>  // Pre-Processive to include standard input and output funtion header files.
#include<stdlib.h>   // Pre-Processive to include standard Libraray funtion header files.

struct node   // Struct Node Stores addres of krnt elm or add of nxt elem.

{  
    int data;  // ele stpre in data
    struct node *next;   // nxt agle elem ka addres isliye pointer bnya hai
};  
struct node *head;  // head only address only for 1st elm // head nam ka pointer 
  
void Insert_1st ();   // Funtion Prototype 
void randominsert();  // Funtion Prototype
void random_delete();  // Funtion Prototype
void display();   // Funtion Prototype
void main ()  
{  
    int choice; 
     printf("\t\t\t\t // Our Heartiest welcome goes to you //    ");
    while(1)   
    {  
		printf("\nMain menu");     
        printf("\n1.Insert in begining");
		printf("\n2.Insert At Specified Position");
		printf("\n3.Delete From A Spefic Position");
		printf("\n4.View ");
		printf("\n5.Exit From Program"); 
        printf("\nEnter your choice\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
              Insert_1st (); 
            break;  
            case 2:  
            randominsert();      
            break;  
			case 3:  
            random_delete();          
            break;  
            case 4:  
            display();        
            break;  
            case 5:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
void Insert_1st ()
{  
    struct node *ptr;   // ptr declre pointer
    int item;  // elem enter 
    ptr = (struct node *) malloc(sizeof(struct node *)); // malloc  
    if(ptr == NULL)  // ptr ==NUlL is space not avaible 
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter value\n");    
        scanf("%d",&item);    
        (*ptr).data = item;     //It is a combination dereference and member-access. // ptr hmri ram hai ptr -> data-> item
        (*ptr).next = head;  //(*ptr).next  ptr->next ( dot pointer) // nxt ka address trnasfer head 
        head = ptr;   // head transfer data to ptr 
        printf("\n Node Succesfully inserted\n");
		printf("\n%d is added In List",item)  ;
    }  
      
}  

void randominsert()  
{  
    int i,loc,item;   // local 
    struct node *ptr, *temp;  //temp:store addes or isko move krvnage head ni krvgnge // if head move har br adrres chnge hoga vo humm chte ni   
    ptr = (struct node *) malloc (sizeof(struct node));  // alocyt
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value");  
        scanf("%d",&item);  
        ptr->data = item;  // ptr(space) -> item se elem leke data me dal ra hai 
        printf("\nEnter the location after which you want to insert ");  
        scanf("\n%d",&loc);   // location mng ra hai 
        temp=head;  // head repace temp.
        for(i=0;i<loc;i++)  // i=o -- location if temp ka adrea node me shift hojgya  
        {  
            temp = temp->next;  
            if(temp == NULL)  // if temp=node elemt insert ni hoga kui ki temp ko null krdiya hai 
            {  
                printf("\ncan't insert\n");  
                return 0;  
            }  
          
        }  
        ptr ->next = temp ->next;   //ptr ka address temp ke nxt me dal re hain 
        temp ->next = ptr;   // ptr a adres hum temp or nxt me store krvre hai 
        printf("\nNode inserted");  
    }  
}  
void random_delete()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc);  
    ptr=head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("\nDeleted node %d ",loc+1);  
}  
void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
} 