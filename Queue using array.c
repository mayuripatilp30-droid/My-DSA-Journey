#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1;
int size;

// Enqueue Operation
void enqueue()
{
    int value;

    if (rear == size - 1)
    {
        printf("\nQueue Overflow! Cannot insert element.\n");
    }
    else
    {
        printf("Enter the element to insert: ");
        scanf("%d", &value);

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        printf("%d inserted into queue.\n", value);
    }
}

// Dequeue Operation
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow! Queue is empty.\n");
    }
    else
    {
        printf("%d deleted from queue.\n", queue[front]);
        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

// Peek Operation
void peek()
{
    if (front == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("Front element = %d\n", queue[front]);
    }
}

// Display Operation
void display()
{
    int i;

    if (front == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nQueue elements are:\n");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Check Empty
void isEmpty()
{
    if (front == -1)
        printf("Queue is Empty.\n");
    else
        printf("Queue is Not Empty.\n");
}

// Check Full
void isFull()
{
    if (rear == size - 1)
        printf("Queue is Full.\n");
    else
        printf("Queue is Not Full.\n");
}

// Main Function
int main()
{
    int choice;

    printf("Enter the size of queue: ");
    scanf("%d", &size);

    queue = (int *)malloc(size * sizeof(int));

    do
    {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
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
                enqueue();
                break;

            case 2:
                dequeue();
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

    free(queue);

    return 0;
}
