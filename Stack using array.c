#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int size;

// Push Operation
void push()
{
    int value;

    if (top == size - 1)
    {
        printf("\nStack Overflow! Cannot insert element.\n");
    }
    else
    {
        printf("Enter the element to push: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("%d pushed into stack.\n", value);
    }
}

// Pop Operation
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow! Stack is empty.\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Peek Operation
void peek()
{
    if (top == -1)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("Top element = %d\n", stack[top]);
    }
}

// Display Operation
void display()
{
    int i;

    if (top == -1)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nStack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

// Check Empty
void isEmpty()
{
    if (top == -1)
        printf("Stack is Empty.\n");
    else
        printf("Stack is Not Empty.\n");
}

// Check Full
void isFull()
{
    if (top == size - 1)
        printf("Stack is Full.\n");
    else
        printf("Stack is Not Full.\n");
}

// Main Function
int main()
{
    int choice;

    printf("Enter the size of stack: ");
    scanf("%d", &size);

    stack = (int *)malloc(size * sizeof(int));

    do
    {
        printf("\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check Empty\n");
        printf("6. Check Full\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
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
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                isEmpty();
                break;

            case 6:
                isFull();
                break;

            case 7:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 7);

    free(stack);

    return 0;
}
