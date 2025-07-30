#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} node;

node* createNode(int data) {
    node* head = (node*)malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed..\n");
        return NULL;
    }
    head->prev = NULL;
    head->data = data;
    head->next = NULL;
    printf("\nFirst node created successfully..\n");
    return head;
}

node* insert_atEnd(node* head, int data) {
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed..\n");
        return head;
    }
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        return temp;
    }

    node* tp = head;
    while (tp->next != NULL)
        tp = tp->next;

    tp->next = temp;
    temp->prev = tp;

    return head;
}

void traverse(node* head) {
    node* temp;
    printf("\nFinal linked list:\n");
    for (temp = head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}

node*delete_at_fisrt(node*head)
{
	head=head->next;
	free(head->prev);
	head->prev=NULL;
	return head;
}

node *delete_last(node*head)
{   //case-1 empty list 
    if(head==NULL){
    	printf("list is empty");
    	return NULL;
	} 
	// case -2 
	if(head->next==NULL){
		free(head);
		printf("last node deleted ..");
		return NULL;
	}
	//case -3
	node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	} // now temp is the last node 
	 temp->prev->next=NULL;
	 free(temp);
	 printf("last node deleted..\n");
	 return head;
}

char choice; //

int main() {
    int data,value;
    
    node* head = NULL;

    printf("___________Welcome to Doubly Linked List_____________\n");

    // First node
    printf("Enter data for the first node: ");
    scanf("%d", &data);
    head = createNode(data);

    // Continue inserting at end based on user input
    while (1) {
        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printf("Enter next data: ");
            scanf("%d", &data);
            head = insert_atEnd(head, data);
        } else if (choice == 'n' || choice == 'N') {
            break;
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }

    // Final list display
    traverse(head);
    printf("want to delte last node?(y/n)");
    scanf(" %c",&choice);
    if(choice=='y'|| choice=='Y')
    {
    	head=delete_last(head);
	} else if (choice=='n'||choice=='N')
	{
		
	}else {
		printf("invalid input.. please enter y / Y");
	}
     traverse(head);
    return 0;
}