//Author: Abhinesha Dhar
//Creation  Date: 09-09-2021
//Purpose: Write a C program compare the running times(in milliseconds) of following
// 1st.Bubble Sort
//2nd.Merge Sort
                          //Respective Array is: {1,3,42,2,41,66,66,33,98,0}

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
	             /*Le is for Arr1 and re is right of the sub-array of arr to be sorted.
                               	Split if there are more than 1 alements: when 
	                     Le<re*/
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
	int take1;                     //Counter variable for printing sort ed.
	for(take1 =0; take1< size; ++take1)
	{
		printf("\nEntered Array is "); 
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
	int arr[10];// declaraing array with size 10 
	int ch;
	printf("\n\n Welcome to Time Machine\n\n");	
    printf("\n Required Array :>> [1, 3, 42, 2, 41, 66, 66, 33, 98, 0 ]   \n\n");
    getInput(arr, 10);  // returns a collection of all INPUT elements in a form. 
	                    // Use optional type and name arguments to restrict the search on these attributes.
    
	clock_t begin = clock(); //The C library function clock_t begin returns the number of clock ticks elapsed since the program was launched.
	
    bubbleSort(arr, 10);  /* Function to for bubblesort an array */
    printArray(arr, 10);  /* Function to print an array */
    printf("\n\n");
    clock_t end = clock();  //The C library function clock_t end returns the number of clock ticks elapsed since the program was ended.
    
    float duration = (float)(end - begin) / CLOCKS_PER_SEC; //  It will convert the number of CPU cycles to the CPU time taken by the process as shown in the following code:
    
	printf("Bubble sort Completed By Compiler In : %f ms\n", duration * 1000); //   // Dividing a count of clock ticks by this expression yields the number of seconds.
    printf("\n\n");
    begin = clock();
    mergeSort(arr, 0, 9); /* Function to for merge_sort an array */
    printArray(arr, 10);   /* Function to print an array */
    printf("\n\n");
    end = clock();
    duration = (float)(end - begin) / CLOCKS_PER_SEC; // It will convert the number of CPU cycles to the CPU time taken by the process .
    printf("Merge sort Completed By Compiler In : %f ms\n", duration * 1000);
	do
	{
		printf("\n 1. For getting question");
		printf("\n 2.For Answer");
		printf("\n 3.Exit from A program");
		scanf("%d",&ch);
		switch(ch)
		{
				case 1:
    		printf("\n\t\tWhich algorithm is faster  Bubble OR Merge and why? ");
    		break;
    	case 2:
    printf("\n\t\t     Which algorithm is faster  Bubble OR Merge and why?\n\n ");
    printf("\n  1.)Bubble sort is a simple sorting algorithm. ");
	printf("\n  2.)This sorting algorithm is comparison-based algorithm in which each pair of adjacent elements is compared and the elements are swapped if they are not in order. ");
	printf(" \n 3.)Just like the movement of air bubbles in the water that rise up to the surface, each element of the array move to the end in each iteration. ");	 
	printf(" \n 4.)Just like the movement of air bubbles in the water that rise up to the surface, each element of the array move to the end in each iteration. ");
	printf(" \n 5.) First Iteration (Compare and Swap)" );
	printf(" \n 6.)   Starting from the first index, compare the first and the second elements.");
	printf("\n  7.)If the first element is greater than the second element, they are swapped. ");
	printf("\n  8.)Now, compare the second and the third elements. Swap them if they are not in order. ");
	printf("\n  9.)The above process goes on until the last element.");
	printf(" \n 10.)The same process goes on for the remaining iterations. ");
	printf(" \n 11.)After each iteration, the largest element among the unsorted elements is placed at the end.");
	printf(" \n 12.)The array is sorted when all the unsorted elements are placed at their correct positions.");
	printf(" \n 13.)Bubble Sort Applications");
	printf(" \n 14.)Bubble sort is used if comlexity does not matter");
	printf(" \n 15.)Bubble sort is used if short and simple code is preferred");
	printf("\n\t\tThanks");
	break;
	case 3: 
{
    printf("\nSuccsively Exited!");
    exit(0);
}

        break;

	default:
        printf("Invalid choice! :/");
           break;
            }
     printf("\n Do you want to continue? (Press y/n): -->    ");
scanf(" %c",&ch);
}while(ch=='y'   || ch=='Y');
}
