#include<stdio.h>
int main()
{
	int size,i;
	printf("enter size of array:");
	scanf("%d",&size);
	int arr[size];
	printf("\nenter %d number:");
	for(i=0;i<size;i++)
	   scanf("%d",&arr[i]);
	printf("\nreversed array is :");
	for(i=size-1;i>=0;i--)
	   printf("%2d",arr[i]);
}