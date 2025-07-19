#include<stdio.h>
void linearSearch(int a[],int range,int search)
{
	int i;
	int c=0;
	for(i=0;i<range;i++)
	{
		if(a[i]==search)
		{
			c++;	
			printf("number is found at %d",i+1);
		    break;
	    }	
	}
	if (c==0)
	{
		printf("number is not  found");
	}
}
void main()
{
	int i,range,search;
	int c=0; // for count the occurance 
	int a[100];
	printf("enter a range :");
	scanf("%d",&range);
	printf("enter %d number:",range);
	for(i=0;i<range;i++)
	  scanf("%d",&a[i]);
	printf("enter a number that you want to search :");
	scanf("%d",&search);
    linearSearch(a,range,search);
}