#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}node;

node * createNode(int data,node *head)
{

	head=(node*)malloc(sizeof(node));
	if(head==NULL)
	{
		printf("memory allocation failed..\n");
		return 0;
	}
	head->prev=NULL;
	head->data=data;
	head->next=NULL;
	printf("\nfirst node created successfully..");
	return head;	
}

node *insert_AtFirst(node *head, int data)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->prev=0;
	temp->data=data;
	temp->next=NULL;
	temp->next=head;
	head->prev=temp;
	head=temp;
	return head;
}
node *traverse(node *head)
{
	node*temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}
node *insert_atEnd(node *head,int data)
{
	node *temp,*tp;
	temp=(node*)malloc(sizeof(node));
	temp->prev=0;
	temp->data=data;
	temp->next=0;// 0 or null both are same 
	tp=head;
	while(tp->next!=NULL)
	   tp=tp->next;
	tp->next=temp;
	temp->prev=tp;
	return head;
}
int main()
{   
    int data;
    node *head;
	printf("___________welcome to doubly linklist_____________\n");
	printf("enter data for the first node:");
	scanf("%d",&data);
	head=createNode(data,head);
	printf("\nenter data for the insert at first :");
	scanf(" %d",&data);
	head=insert_AtFirst(head,data);
	traverse(head);
   //	head=insert_atEnd(head,3);
   // traverse(head);	
}