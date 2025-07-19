#include<stdio.h>
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

    for(i=0;i<range;i++)
	{
		if(a[i]==search)
		{
				
			printf("number is found at %d",i+1);
			c++;
		    break;
	    }	
	}
	if (c==0)
	{
		printf("number is not  found");
   
   }
}