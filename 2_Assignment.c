//Author: Abhinesha Dhar
//Creation  Date: 09-09-2021
//Purpose: Write a C program compare the running times(in milliseconds) of following
// 1st.Bubble Sort
//2nd.Merge Sort
//Required Array is: {1,3,42,2,41,66,66,33,98,0}

#include<stdio.h>  //Pre-Procrssive to include standard input and output function header files.
#include<stdlib.h>
#include<time.h>  //The time.h header file contains definitions of functions to get and manipulate date and time information.

int k1,k2;

void swap(int*var1,int*var2)  //pass the address of the variable to swap
{
	int head;  //Declaraing head variable to store address of variable 1 and 2 respectively.
	head =*var1;  //Assigning variable 1 to Head.
	*var1 = *var2;
	*var2 = head;
} 
void bubbleSort(int*arr, int size)
{
	int i,j;  //Declaring i as sort_index and j as unsorted_index.
	for(i=0;i<(size-1);++i)  //initating for loop.
	{
		for(j=0;j<(size-(i+j));++j)
		{
			if(arr[j]>arr[j+1])  //Using if loop for iterating array.
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}
void merge(int*arr, int le, int me, int re)
{
	k1 = me-le+1;
	k2 = re-me;  //re-(me+1)+1;
	int Arr1[k1], Arr2[k2];  //Declaraing Two Array Variables with int data type.
	int a,b,c;
	//Copy data to temp array Arr1[] and Arr2[] */
	for(a=0; a< k1; a++)
		Arr1[a] = arr[le+a];
	for(b=0; b< k2; b++)
		Arr2[b] = arr[(me+1)+b];
	b=0;  //Initial index of First or left  subarray.
	a=0;  //Initial index of Second or right subarray.
	c=le;  //Initial index of merged  subarray
	while(a<k1 && b<k2)
	{
		if(Arr1[a]<=Arr2[b])
		{
			arr[c] = Arr1[a];
			a++;
		}
		else
		{
			arr[c] = Arr2[b];
			b++;
		}
		c++;
	}
	while(a< k1)  //Right is empty.
	{
		arr[c]= Arr1[b];
		b++;
		c++;
	}
}
void mergeSort(int*arr, int le, int re)  //Recursive function.
{
	int me;
	/*LeftElementIn is for left indexand ris right of the sub-array of arr to be sorted.
	Split if there are more than 1 alements: when 
	LeftElementIn<rightElementIn*/
	if(le<re)
	{
		/*Split the array and length =(r-1)+1
		we will use (1+r)/2 */
		me=(le+re)/2;  //Call mergeSort() for left subarray.
		mergeSort(arr, le, me);  //Call mergeSort() for right subarray.
		mergeSort(arr, me+1, re);  //merge the left and right subarray.
		merge(arr, le, me, re);
	}
}

int printArray(int *arr, int size)
{
	int take1;  //Counter variable for printing sort ed.
	for(take1 =0; take1< size; ++take1)
	{
		printf("\nArray Your Entered Is...."); 
		printf("\narr[%d]=%d", take1,*(arr+take1));  //Printing the Required Array. 
	}
	return(take1+1);  //returns the number of elements printed.
}

int getInput(int *arr, int size)
{
	int take2;  //Counter variable for taking unsorted array
	for(take2= 0; take2< size; ++take2)
	{
		printf("Enter arr[%d]=",take2);
		scanf("%d",(arr+take2));  //Taking array from user.  
	}
	return(take2+1);  //return the number of elements read.
}

int main()
{
	int arr[10];  //Declaraing array with size 10
	int ch;
	printf("\n\n\t\t\t\t\t\t Welcome to Tme machine\n\n");
	printf("\n \t\t HG$$  ---->>>>> Time Calculator  <<<<<-----Hg$$\n\n\n");
	printf("\nRequired Array:>>[1,3,42,2,41,66,66,33,98,0] \n\n");
	
	getInput(arr, 10);  //Getchar() function reads the next available character from the screen and returns it as an integer.
	
	clock_t begin= clock();  //The C library  function clock_t begin returns the number of clock ticks elapsed since the program was launched.

	bubbleSort(arr, 10);   /* Function to for bubbleSort an array*/
	printArray(arr, 10);   /*Function to print an array*/
	printf("\n\n");

	clock_t end= clock();  //The C library function clock_t end returns the number of clock  ticks elapsed since the program was ended.

	float duration= (float)(end-begin)/CLOCKS_PER_SEC;  //It will convert the number of CPU cycles to the CPU time taken by the process as time shown in the following codes:
	printf("MergeSort Completed by compiler In:%f ms\n",duration*1000);
	do
	{
		printf("\n 1.Press 1 for getting question");
		printf("\n 2.Press 2 for Answer");
		printf("\n 3.Exit from A program");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("\n\t\t Which algorithm is faster Bubble or Merge and why?");
			break;
			
			case 2:
			printf("MergeSort completed by compiler In:%f ms\n", duration*1000);  //Dividing a count of clock ticks by this expression yields the number of seconds.
			printf("\n\t\t Which algorithm is faster Bubble or merge and why?");

			printf("\n 1.)MergeSort is considered to be one of the fastest sorting algorithms");
			printf("\n 2.)It is a bit more complex than Selection and bubbleSort but its more efficient.");
			printf("\n 3.)The idea of MergeSort is to divide the data-set into smaller data-sets");
			printf("\n 4.)Sort those smaller data-sets and then join them(merge them) together.");
			printf("\n 5.)The way this algorithm behaves is by sorting the left side of the data-set first then the right part and them merging tem.");
			printf("\n 6.)Merge sort will divide in two the data-set until all the elements are separate");
			printf("\n 7.)Then it will start joining from left to right in pairs then those pairs will merge from left to right");
			printf("\n 8.)Until there are only two bigger pairs to join.");
			printf("\n 9.)If we think about it, this makes it easy to merge because if we have two parts of a data-set that are both sorted");
			printf("\n 10.)We can then compare the first element in one data-set with the others");
			printf("\n 11.)Determine which one is smaller, therefore  pushing that smaller element first into a new data-set.");

			case 3: exit(0);
			break;

			default:
			printf("Invalid choice! :/");
			break;
		}
		printf("\n Do you want to continue?(Press y/n)");
		scanf("%c",&ch);
	}while(ch=='y');
}