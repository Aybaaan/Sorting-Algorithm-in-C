/*
Create a program that will ask the user 
to input N amount of numbers in an array. 
Let the user choose the type of searching 
and sorting to be used 
(even if it shall yield the same output).
Ask the user for a number and input the 
nth position of the number together with the 
sorted array.
*/

#include <stdio.h>
#include <stdlib.h>

void swap (int *xp, int *yp);
int binary (int arr[], int n, int find);
int linear (int arr[], int n, int find);
void bubble (int arr[], int n);
void selection (int arr[], int n);
void insertion (int arr[], int n);
void printarray (int arr[], int n);
void poscheck(int pos);

int main (){
	int opt1, opt2, num, i, j, find, pos;
//	system("cls");
		
	printf("\n\tEnter number of elements:");
	scanf("%d",&num);
	
	int arr[num-1];
	
	printf("\tEnter %d numbers:\n",num);
	for(i=0;i<num;i++){
		printf("\t");
		scanf("%d",&arr[i]);
	}
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printf("\n\tChoose type of Sorting:");
	printf("\n\t1.Bubble");
	printf("\n\t2.Selection");
	printf("\n\t3.Insertion");
	printf("\n\tEnter Option:");
	printf("\t");
	scanf("%d",&opt1);
	
	switch(opt1){
		case 1: bubble(arr,n); break;
		case 2: selection(arr,n); break;
		case 3: insertion(arr,n); break;
		default: return main();
	}
	
	printf("\n\tChoose type of Searching:");
	printf("\n\t1.Linear");
	printf("\n\t2.Binary");
	printf("\n\tEnter Option:");
	printf("\t");
	scanf("%d",&opt2);
	
	printf("\n\tEnter number to find:");
	printf("\t");
	scanf("%d",&find);
	
	switch(opt2){
		case 1: pos = linear(arr,n,find); break;
		case 2: pos = binary(arr,n,find); break;
		default: return main(); 
	}
	
	printarray(arr,n);
	poscheck(pos);
	
	return main();
}

void swap (int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
int binary (int arr[], int n, int find){
	int i, pos, hi, lo;
	hi = n;
	lo = 0;
	
	while (lo + 1 < hi){
		pos = (lo + hi)/2;
		if (arr[pos] >= find){
			hi = pos;
		}
		else
			lo = pos;
	}
	
	if (arr[hi]==find)
		return hi;
	else
		return -1;
	
}

int linear (int arr[], int n, int find){
	int i, pos;
	for(i=0;i<=n;i++){
		if (find == arr[i]){
			pos = i;
			break;
		}
		else
			pos = -1;
	}
	
	return pos;
}

void bubble (int arr[], int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(arr[j]>arr[j+1])
				swap(&arr[j+1],&arr[j]);
}

void selection (int arr[], int n){
	int i,j,min;
	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;j<=n;j++)
			if(arr[j]<arr[min])
				min = j;
		swap(&arr[min],&arr[i]);
	}
}

void insertion (int arr[], int n){
	int i, j, key;
	for(i=1;i<=n;i++){
		key=arr[i];
		j = i - 1;
		
		while (j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		
		arr[j+1] = key;
	}
}

void printarray (int arr[], int n){
	printf("\t");
	for(int i=0;i<=n;i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void poscheck(int pos){
	if (pos == -1)
		printf("\n\tKey value not found!\n");
	else
		printf("\n\tKey value found at position %i\n", pos+1);
}
