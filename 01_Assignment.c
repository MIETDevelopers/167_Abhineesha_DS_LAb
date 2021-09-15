#include <stdio.h>
#include <stdlib.h>
void create();
void name();
void prize();
void buy();
struct shop
{
	char shopname[50];
    char items[10];
    int rate;
    struct shop *next;
};
typedef struct shop node;
node *head = NULL;
int main()
{
	int ch;
    create();
    printf("Welcome To Raghunath Bazaar!\n");
    while (1)
    {
    	printf("\nPlease Choose From The Following:\n1.To View Shops Names\n2.To View Prize And Items\n3.To View Shop Name For Cheapest Walnuts\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
          name();
          break;
        case 2:
          prize();
          break;
        case 3:
          buy();
          break;
        case 4:
          exit(0);
        default:
           printf("Wrong Choice!");
        }
    }
}
void create()
{
 
  node *shop, *temp;
  int n;
  printf("How many shops you want to create\n");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {

    shop = (node *)malloc(sizeof(node));
    if (shop == NULL)
    {
    	printf("unable to create node");
    }
    else
    {
    	fflush(stdin);
        printf("Enter your %d shop name\n", i+1);
        scanf("%[^\n]", shop->shopname);
        fflush(stdin);
        printf("Enter your %d shop item\n",i+1);
        scanf("%[^\n]", shop->items);
        printf("Enter your %d shop item rate\n", i+1);
        scanf("%d", &shop->rate);

        shop-> next = null
        if (head == NULL)
        {
           head = temp = shop;
        }
        else 
        {

          temp->next = shop;
          temp = shop;
        }
    }
  }
}

void name()
{
   node *temp;
   temp = head;
   if (temp == NULL)
   {
   	 printf("List is empty\n");
   }
   else
   {
      for (int i = 0; temp != NULL; i++)
     {
       printf("Shop number %d name is %s\n", i+1, temp->shopname);
       temp = temp->next;
     }
  }
}
void prize()
{
	node *temp;
    temp = head;
    if (temp == NULL)
    {
      printf("List is empty\n");
    }
    else
    {
      for (int i = 0; temp != NULL; i++)
       {
          printf("The shop of %s is selling %s at %dRs\n", temp->shopname, temp->items, temp->rate);
          temp = temp->next;
        }
    }
}
void buy()
{
	node *temp;
    node *lowest;
    int low = temp->rate;
    temp = head;
    if (temp == NULL)
    {
    	printf("List is empty");
    }
    else
    {
      while (temp != NULL)
       {

          if (temp->rate < low)
            {
            	low=temp->rate;
                lowest = temp;
            }
            temp = temp->next;
        }
        printf("The shop of %s will give lowest prize which is %d on %s\n", lowest->shopname, low,lowest->items);
    }
}
