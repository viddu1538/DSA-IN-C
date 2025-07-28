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
		q=r; // to point new last node   , 
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
 
 
node *insert_position(node *head)
{
	node *n,*z; // z for loop and n for new node 
	int pos,c=0;
	printf("\nenter position for new node : ");
	scanf("%d",&pos);
	n=(node *)malloc(sizeof(node));
	printf("\n enter data for new node ");
	scanf("%d",&n->data);
	n->next=NULL;
	
	for(z=head; z!=NULL;z=z->next)
	{
		c++;
		if (c==pos-1)
		{
			n->next=z->next;
			z->next=n;
			break;
		}
	}	
	return head;				
}

int main()
{
	node *h;
	h=createNode();
	traverse(h);
	h=insert_position(h);	
	traverse(h);
	
}