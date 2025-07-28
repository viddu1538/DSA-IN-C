/** this is a linklist program in which we take user input in linklist and then 
print/travere the linklist   and then we insert a node at start */
#include<stdio.h>
#include<stdlib.h>  // for malloc and calloc function 
typedef struct node  // this node has two member 1st is int type and second is self refrential 
{
int data;
struct node  *next;  // self refrential structure 
}node;

node * createNode()
{
	node *head,*q,*r;
	char ch;
	head=(node *)malloc(sizeof(node));
	printf("enter data:");
	scanf("%d",&head->data);
	head->next=NULL;
	q=head;
	printf("first node created succesfully.\n");
	printf("want more node ?(y/n)");
	scanf(" %c",&ch);
	while(ch=='y'||ch=='Y')
	{
		r=(node*)malloc(sizeof(node));
		printf("enter data:");
		scanf("%d",&r->data);
		r->next=NULL;
		q->next=r;
		q=r; // to point new last node   , q is for 
		printf("want more node ?(y/n)");
    	scanf(" %c",&ch);
	}
	return head;	
}
void traverse(node *head)
{
	node *h; // for temporary loop 
	for(h=head;h!=NULL;h=h->next)
	   printf("%5d",h->data);
}
 
 
node *insert_first(node *head)
{
	node *new;
	new=(node *)malloc(sizeof(node));
	printf(" \nenter data for the new node :");
	scanf("%d",&new->data);
	new->next=NULL;
	new->next=head;
	head=new;
	return head;
}
int main()
{
	node *h;
	h=createNode();
	traverse(h);
	h=insert_first(h);
	traverse(h);
	
}