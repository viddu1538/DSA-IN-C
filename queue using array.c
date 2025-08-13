#include<stdio.h>
int queue[10];
int front=-1;   // removal end 
int rear=-1;   // insertion end 

void insertq(int data)
{
    if (front>=0 && rear==9){
		printf("\nqueue is full");
		return;
    }
    else if (front==-1 && rear==-1){  // means both are at -1 means queue is empty 
    	rear++;
    	front++;
    	queue[rear]=data;
	}
	else{
		rear++;
		queue[rear]=data;
	}
}
void deleteq()
{
	if(front==-1 && rear==-1){
		printf("\nqueue is empty");
		return;
	}
	else if(front==rear){
		front=-1;   // front=rear=-1;
		rear=-1;
	}
	else 
	    front++;
	    printf("\n one data deleted");
	    
}
void showq()
{
	int i;
	if(front==-1 && rear==-1){
		printf("\nqueue is empty");
		return;
	}
	for(i=front;i<=rear;i++)
	{
		printf("\n%5d",queue[i]);
	}
}

int main()
{
	insertq(5);
	insertq(10);
	insertq(15);
	insertq(20);
	insertq(25);
	showq();
	deleteq();
	showq();
	deleteq();
	showq();	
}