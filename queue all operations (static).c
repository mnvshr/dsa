#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define capacity 5

int queue[capacity], front = 0, rear = 0;

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
        printf("- - - QUEUE MENU - - - \n\n");

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
        printf("Invalid Input \n\n");
        break;
        }
    }
    getch();
}

int input()
{
    int n;

    scanf("%d", &n);

    return n;
}

int isFull()
{
    /* if ((front == -1 && rear == capacity - 1) || (rear = front - 1)) */
    if (front == 0 && rear == capacity - 1)
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
    if (isFull())
    {
        printf("Queue is full \n");
    }
    else
    {
        int element;

        printf("Enter the element you want to insert: ");
        scanf("%d", &element);

        queue[rear] = element;
        rear++;

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
        printf("Deleted item is %d \n", queue[front]);
        for (int i = front; i < rear - 1; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear--;
    }
}

void display()
{
    if (front == rear)
    {
        printf("Queue is empty \n");
    }
    else
    {
        printf("Queue elements are: \n");

        for (int i = front; i < rear; i++)
        {
            printf("Element %d: %d \n", i, queue[i]);
        }
    }
}
