#include <stdio.h>
#define MAXSIZE 50

int top = -1;
int stack[MAXSIZE];

void push();    // prototyping  
void pop();
void display();

int main()
{
    int choice;  // top will be -1 that is 0th index se niche     
    do
    {
        printf("__________________stack____________________\n");
        printf("1. push\n2. pop\n3. display\n4. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }
    } while (choice != 4);
    printf("thanks for  using this program..");
}

void push()
{
    int n;
    if (top == MAXSIZE - 1)
        printf("stack is full..\n");
    else
    {
        printf("\nenter an element: ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
    }
}

void display()
{
    int i;
    if (top == -1)
        printf("stack is empty\n");
    else
    {
        printf("\nelements of stack are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void pop()
{
    int n;
    if (top == -1)
        printf("stack is empty\n");
    else
    {
        n = stack[top];
        top--;
        printf("popped item is %d\n", n);
    }
}