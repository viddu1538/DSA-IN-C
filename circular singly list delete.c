#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

// Create a circular singly linked list
node* createList(int size) {
    if (size <= 0) return NULL;

    int data;
    node *tail = NULL, *temp;

    // Create first node
    printf("Enter data for node 1: ");
    scanf("%d", &data);

    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = temp;  // Pointing to itself for circular nature
    tail = temp;

    // Create remaining nodes
    for (int i = 2; i <= size; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        temp = (node*)malloc(sizeof(node));
        temp->data = data;
        temp->next = tail->next; // Pointing to head
        tail->next = temp;
        tail = temp;
    }

    printf("\nLinked list created successfully.\n");
    return tail;
}

// Traverse circular list
void displayList(node* tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* temp = tail->next; // Head node
    printf("Circular Linked List: ");
    do {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    
}
node *deleteFirst(node*tail)
{
	if(tail==NULL) return NULL;
	if (tail->next==tail)
	{
		free(tail);
		tail=NULL;
		return NULL;
	}
	node* temp=tail->next;
	tail->next=temp->next;
	free(temp);
	temp=NULL;
	return tail;
}

int main() {
    int size;
    char ch;
    printf("____________WELCOME TO CIRCULAR SINGLY LINKED LIST____________\n");
    printf("Enter how many nodes you want to create: ");
    scanf("%d", &size);

    node* tail = createList(size);
    displayList(tail);
    printf("\nwant to deldete first ?(y/n)");
    scanf(" %c",&ch);
    switch (ch)
    {
    	case 'y':
    		if(tail==NULL)
    		{
    			printf("list is empty can't be deleted");
			}else {
				tail=deleteFirst(tail);
				displayList( tail);
				break;
			}
		case 'Y':
			if(tail==NULL)
    		{
    			printf("list is empty can't be deleted");
			}else {
				tail=deleteFirst(tail);
				displayList( tail);
				break;
			}
		case 'n':
			printf("thanks for using the program.");
			break;
		case 'N':
			printf("thanks for using the program.");
			break;			
	}

    return 0;
}