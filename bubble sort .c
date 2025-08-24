// bubble sort
#include<stdio.h>
int main(){  
	int i,k,range;  // k= outer loop , i= inner loop , range = user inout size
	printf("enter the range :");
	scanf("%d",&range);
	int a[range];
	printf("enter %d numbers :",range);
	for(i=0;i<range;i++)
	{
		scanf("%d",&a[i]);
	}
	for(k=0;k<range;k++)  // outer loop 
	{
		for(i=0;i<range-1;i++)  //inner loop 
	    {
		    if(a[i]>a[i+1])
		    {
			int temp;
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		    }
	    }
	}
	printf("after sorting  the array is \n");
	for(i=0;i<range;i++)
	{
		printf("%d ",a[i]);
	}

}
