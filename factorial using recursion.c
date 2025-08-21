#include<stdio.h>
int fact(int n)
{
	if(n>0)
	{
	 return (n*fact(n-1));
	}
	else
	  return 1;	
}
int main()
{
	int x;
	printf("enter a number for factorial :");
	scanf("%d",&x);
	int result=fact(x);
	printf("factorial of %d =%d",x,result);
}