#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int value);
int dequeue();
void display();

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n  Enter Your Choice  ( Circular Queue )\n");
        printf("1. For Enqueue\n");
        printf("2. For Dequeue\n");
        printf("3. For Display\n");
        printf("4. For Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            value = dequeue();
            if (value != -1)
            {
                printf("Removed element: %d\n", value);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}

void enqueue(int value)
{
    if ((front == 0 && rear == MAX_QUEUE_SIZE - 1) || (front == rear + 1))
    {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX_QUEUE_SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = value;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX_QUEUE_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return value;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are:\n");
    int i = front;
    if (front <= rear)
    {
        while (i <= rear)
        {
            printf("%d ", queue[i]);
            i++;
        }
    }
    else
    {
        while (i <= MAX_QUEUE_SIZE - 1)
        {
            printf("%d ", queue[i]);
            i++;
        }
        i = 0;
        while (i <= rear)
        {
            printf("%d ", queue[i]);
            i++;
        }
    }
    printf("\n");
}
