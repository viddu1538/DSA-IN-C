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
node *insert_Atposition(node*head,int position,int value)
{
	int count=1;
	node* temp,*newnode;
	temp=head;
	newnode=(node*)malloc(sizeof(node));
	while(temp!=NULL && count<position-1)
	{
		temp=temp->next;
		count++;
	}
	newnode->next=temp->next;
	newnode->data=value;
	newnode->next->prev=newnode;
	temp->next=newnode;
	newnode->prev=temp;
	return head;
}

int main() {
    int data,position,value;
    char ch;
    node* head = NULL;

    printf("___________Welcome to Doubly Linked List_____________\n");

    // First node creation
    printf("Enter data for the first node: ");
    scanf("%d", &data);
    head = createNode(data);

    // Subsequent node insertions at end
    do {
        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y') {
            printf("Enter next data: ");
            scanf("%d", &data);
            head = insert_atEnd(head, data);
        }
    } while (ch == 'y' || ch == 'Y');

    // Display final list
    traverse(head);
    printf("enter a position where you want to enter a data :");
    scanf("%d",&position);
    printf("enter data for %d \'th positon ",position);
    scanf("%d",&value);
    head=insert_Atposition(head, position,value);
    traverse(head);

    return 0;
}