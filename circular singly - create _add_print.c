#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data ;
	struct node* next;
}node;

node* addToEmpty(int data)
{
	node* temp=(node*)malloc(sizeof(node));
	if(!temp)
	{
		printf("memory allocation failed!");
		return NULL;
	}
	temp->data=data;
	temp->next=temp;
	return temp;
}

node *addAtBeg(node *tail,int data)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=tail->next;
	tail->next=temp;
	return tail;
}
void print(node*tail)
{
	node*temp;
	temp=tail->next;
	do
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}while(temp!=tail->next);
}
int main()
{
	printf("_________welcome to circular linklist________");
	node*tail=NULL;
	int data;
	printf("\nenter a  data for the first node:");
	scanf("%d",&data);
	tail=addToEmpty( data);
	printf("\nenter a data for the begining :");
	scanf("%d",&data);
	printf("i am taking some random data:\n");
	tail=addAtBeg(tail,data);
	tail=addAtBeg(tail,20);
	tail=addAtBeg(tail,30);
	tail=addAtBeg(tail,40);
	print(tail);
	return 0;
}