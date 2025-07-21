#include<stdio.h>
void main()
{
	int range;
	printf("enter range:");
	scanf("%d",&range);	
	int a[range];
	int p,s,index,temp,min;
	printf("ender %d numbers :",range);
	for(p=0;p<range;p++)
	{
		scanf("%d",&a[p]);
	}
	for(p=0;p<range-1;p++)
	{
		min=a[p];
		index=p;
		for(s=p+1;s<range;s++)
		{
			if(min>a[s])
			{
				min=a[s];
				index=s;
			}
		}
		temp=a[p];
		a[p]=a[index];
		a[index]=temp;
	}
	printf("after sorting \n");
	for(p=0;p<range;p++)
	{
		printf("%d ",a[p]);
	}
}