#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node * prev;
	struct Node *next;
}node;

node* createList(int data)
{
	
	node*newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL)
	{
		printf("\nmemory allocation failed..");
	}
	newnode->data=data;
	newnode->next=newnode;
	newnode->prev=newnode;
	return newnode;
	
}
node*insertAtBegning(node*head,int data)
{
	node*newnode=(node*)malloc(sizeof(node));
	if(!newnode)
	{
		printf("memory allocation failed..");
		return newnode;
	}
	newnode->data=data;
	if (head==NULL) // treat like empty list 
	{
		
		newnode->prev=newnode;
		newnode->next=newnode;
		return newnode;
	}
	node*tail=head->prev;
	newnode->next=head;
	newnode->prev=tail;
	tail->next=newnode;
	head->prev=newnode;
    return newnode;  //newnode becomes the first node 
}
void traverse(node*head)
{
	if(head==NULL)
	{
		printf("memory allocation failed.");
		return  ;
	}
	node*temp=head;
	do
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}while(temp!=head);
	 printf("\n");
}
int main()
{
	node*head=NULL;
	head=insertAtBegning(head,30);
	head=insertAtBegning(head,20);
	head=insertAtBegning(head,10);
	head=insertAtBegning(head,5);
	traverse(head);
	return 0;
}