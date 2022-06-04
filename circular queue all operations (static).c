#include <stdio.h>
#include <stdlib.h>

#define capacity 10

int queue[capacity], front = -1, rear = -1;

void insert();
void delete();
void display();
int input();
int isFull();
int isEmpty();

void main()
{
    while (1)
    {
        printf("\n- - - CIRCULAR QUEUE MANU - - -\n");

        printf("1. INSERT \n");
        printf("2. DELETE \n");
        printf("3. DISPLAY \n");
        printf("4. EXIT \n");

        printf("Enter your choice: ");
        int n = input();

        switch (n)
        {
        case 1:
        insert();
        break;

        case 2:
        delete();
        break;

        case 3:
        display();
        break;

        case 4:
        exit(0);
        break;
        
        default:
        printf("Invalid input\n");
        break;
        }
    }
    
}

int input()
{
    int n;

    scanf("%d", &n);

    return n;
}

int isFull()
{
    if ((front == 0 && rear == capacity - 1) || rear == front - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert()
{
    int element;

    if (isFull())
    {
        printf("Queue is full \n");
    }
    else
    {
        printf("Enter the element you want to insert: ");
        scanf("%d", &element);

        if (isEmpty())
        {
            rear = front = 0;
            queue[rear] = element;
        }
        else if (rear == capacity - 1)
        {
            rear = 0;
            queue[rear] = element;
        }
        else
        {
            rear++;
            queue[rear] = element;
        }
    printf("%d inserted\n", element);
    }
}

void delete()
{
    if (isEmpty())
    {
        printf("Queue is empty \n");
    }
    else
    {
        printf("\nDeleted element is: %d", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty \n");
    }
    else
    {
        if (front > rear)
        {
            for (int i = front; i < capacity - 1; i++)
            {
                printf("%d\t", queue[i]);
            }
            for (int j = 0; j <= rear; j++)
            {
                printf("%d\t", queue[j]);
            }    
        }
        else if (front < rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d\t", queue[i]);
            }
        }
    }
}
