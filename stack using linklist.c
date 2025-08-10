/* this is the menu driven program of stack using linklist in which 
user got 4 options :-
1.push
2.pop
3.display
4.exit
they have to select one option to perform that action 
thanks 
date:-10th august 2025
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node*next;
}node;

node*top=NULL;  // this is the global declaration of top 
void  push(int data)
{   
    node*temp=(node*)malloc(sizeof(node));
	if(temp==NULL)
	{
		printf("stack is full..");
		free(temp);
	}else{
		node*newnode=(node*)malloc(sizeof(node));
		newnode->data=data;
		newnode->next=top;
		top=newnode;
		printf("\n%d pushed to stack ",data);
	}
}
void pop()
{   
	if(top==NULL)
	    printf("\nstack is empty!");
	else{
	    node*p;
		p=top;
		top=top->next;
		printf("\n%d is deleted",p->data);
		free(p);
	}
}
void display()
{
	node*p=top;
	if(p==NULL){
		 printf("stack is empty.");
		 return ;
	}	    
	printf("\nstack data are:");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
    }  
}
int main()
{
   /* push(20);
	push(30);
	push(80);
	push(44);
	display();
	pop();
	display();*/
  
    while(1)
    {
   	int choice,data;
	printf("\n____________________stack program_____________________");
	printf("\n1.push");
	printf("\n2.pop");
	printf("\n3.display");
	printf("\n4.exit");
	printf("\n\nselect one option(1,2,3,4):");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nenter data:");
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
			printf("\nThanks for using this program..");
			return 0;
		default:
			printf("\ninvalid selection try again.");
	}
	}
	
}