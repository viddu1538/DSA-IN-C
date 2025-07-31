#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* addToEmpty(int data) {
    node* temp = (node*)malloc(sizeof(node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    temp->data = data;
    temp->next = temp;
    return temp;
}

node* addAtBeg(node* tail, int data) {
    if (!tail) {
        return addToEmpty(data);
    }
    node* temp = (node*)malloc(sizeof(node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return tail;
    }
    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;
    return tail;
}

node* addAtEnd(node* tail, int data) {
    if (!tail) return addToEmpty(data);

    node* temp = (node*)malloc(sizeof(node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return tail;
    }
    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;
    return temp;  // New tail
}

node* insert_atPosition(node* tail, int data, int pos) {
    if (tail == NULL || pos < 1) {
        printf("Invalid operation: Empty list or invalid position.\n");
        return tail;
    }

    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return tail;
    }

    newNode->data = data;
    newNode->next = NULL;

    node* curr = tail->next;

    if (pos == 1) {
        newNode->next = curr;
        tail->next = newNode;
        return tail;
    }

    for (int i = 1; i < pos - 1; i++) {
        curr = curr->next;
        if (curr == tail->next) {
            printf("Position exceeds list length.\n");
            free(newNode);
            return tail;
        }
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return tail;
}

void print(node* tail) {
    if (!tail) {
        printf("List is empty.\n");
        return;
    }
    node* temp = tail->next;
    do {
        printf(" %d", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

int main() {
    node* tail = NULL;
    int choice, data, pos;

    printf("_________Welcome to Circular Linked List_________\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add to empty list\n");
        printf("2. Add at beginning\n");
        printf("3. Add at end\n");
        printf("4. Insert at position\n");
        printf("5. Print list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (tail != NULL) {
                    printf("List is not empty! Use add at beginning instead.\n");
                } else {
                    printf("Enter data for first node: ");
                    scanf("%d", &data);
                    tail = addToEmpty(data);
                }
                break;

            case 2:
                if (tail == NULL) {
                    printf("List is empty! Use add to empty list first.\n");
                } else {
                    printf("Enter data to add at beginning: ");
                    scanf("%d", &data);
                    tail = addAtBeg(tail, data);
                }
                break;

            case 3:
                if (tail == NULL) {
                    printf("List is empty! Add to empty list first.\n");
                } else {
                    printf("Enter data to add at end: ");
                    scanf("%d", &data);
                    tail = addAtEnd(tail, data);
                }
                break;

            case 4:
                if (tail == NULL) {
                    printf("List is empty! Add to empty list first.\n");
                } else {
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    printf("Enter position to insert at: ");
                    scanf("%d", &pos);
                    tail = insert_atPosition(tail, data, pos);
                }
                break;

            case 5:
                printf("Circular linked list: ");
                print(tail);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}