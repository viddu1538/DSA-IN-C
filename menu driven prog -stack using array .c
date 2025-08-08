// Stack program using array 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 10
int top=-1;
int stack[SIZE];

	bool isFull()  // this function is check if stack is full then return true 
	{              // if not full then return false 
		if(top==SIZE-1)
		{
			return true;
		}else{
			return false;
		}
	}
	
	bool isEmpty()
	{
		if(top==-1)
		 return true;
		else
		return false;
	}
	
	void push(int data)
	{
		if(!isFull())
		{
			top=top+1;  // or top++
			stack[top]=data;
		}
		else {
			printf("stack full can't push (cause overflow)");
		}
	}
	
	int pop()
	{
		if(!isEmpty())
		{
			int data;  /// that will be popped 
			data=stack[top];
			top=top-1;  // or top--
		} else{
			printf("stack is empty can't pop (underflow )'");
		}
	}

int display()
{
	int i;  // for traverse the stack
	for (i=0;i<=top;i++)
	{
		printf("%d ",stack[i]);
	}
}

int main()
{ 
   int x,data;
    printf("_________________stack menu driven program___________________");
   while(1)
   {
   printf("\n\n1.push");
   printf("\n2.pop");
   printf("\n3.display");
   printf("\n4.exit");
   printf("\nselect the function(1 or 2 or 3 ):");
   scanf("%d",&x);
   
   	switch(x)
   {
   	  case 1:
   	  	printf("enter data:");
   	  	scanf("%d",&data);
   	  	push(data);
   	  	break;
   	  case 2:
   	  	pop();
   	  	break;
   	  case 3:
   	  	display();
   	  	break;
   	  case 4:
   	  	printf("exiting the program..");
   	  	return 0;
   	  default :
   	  	printf("\n invalid selection..");
   	  	break;
   }
   }
  push(10);
  push(20);
  push(30);
  push(40);
  display();
  
  	
}