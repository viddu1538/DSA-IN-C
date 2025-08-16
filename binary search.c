// this progaram is about binary search 
#include<stdio.h>
int  main()
{
	int a[20];
	int l,r,range,i,search,m;
	printf("enter range :");
	scanf("%d",&range);
	printf("enter %d value :",range );
	for(i=0;i<range;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter a number for search :");
	scanf("%d",&search);
	l=0;  // l is for left 
	r=range-1;  // r is for right 
	
	while(l<=r){
		m=(l+r)/2;  
		if(a[m]==search){
		printf("number is found at position %d ",m+1);
		break;
	}
	else if (a[m]<search){
		l=m+1;
	}
	else if (a[m]> search){
		r=m-1;
	}
	}
	if(l>r){
		printf("number is not found ");
	}	

}
