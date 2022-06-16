#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define size 10

int isEmpty();
int isFull();
void insert(int, int);
int highestPriority();
int delete();
void display();

int rear = -1, front = -1;

struct pq
{
    int ele, priority;
} pq[size];

void main()
{
    int ch, p, ele;

    while (1)
    {   
        printf("\n- - - PRIORITY QUEUE - - -\n");

        printf("1. INSERT\n");
        printf("2. GET HIGHEST PRIORITY ELEMENT\n");
        printf("3. DELETE HIGHEST PRIORITY ELEMENT\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (isFull())
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                printf("Enter priority: ");
                scanf("%d", &p);
                insert(ele, p);
            }
            break;

        case 2:
            if (isEmpty())
            {
                printf("Queue is empty\n");
            }
            else
            {
                p = highestPriority();
                printf("Element = %d, Highest priority = %d |", ele, p);
            }
            break;
        
        case 3:
            if (isEmpty())
            {
                printf("Queue is empty\n");
            }
            else
            {
                ele = delete();
                printf("Deleted\n");
            }
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;

        default:
            break;
        }
    }
    getch();
}

int isEmpty()
{
    if (rear == -1 && front ==  -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (rear == size - 1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void insert(int ele, int p)
{
    rear++;
    pq[rear].ele = ele;
    pq[rear].priority = p;
}

int highestPriority()
{
    int p = -1;

    if (isEmpty())
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < rear; i++)
        {
            if (pq[i].priority > p)
            {
                p = pq[i].priority;
            } 
        }
        return p;
    } 
}

int delete()
{
    int p, ele, i, j;

    p = highestPriority();

    for (i = 0; i < rear; i++)
    {
        if (pq[i].priority == p)
        {
            ele = pq[i].ele;
            break;
        }
    }
    if (i < rear)
    {
        for (j = i; j < rear; j++)
        {
            pq[j].ele = pq[j + 1].ele;
            pq[j].priority = pq[j + 1].priority;
        }
    }
    rear = rear - 1;
    return ele;
}

void display()
{
    if(isEmpty())
    {
        printf("Queue is emplty\n");
    }
    else
    {
        printf("\nPriority Queue = ");

        for (int i = 0; i <= rear; i++)
        {
            printf("Element = %d, Priority = %d |", pq[i].ele, pq[i].priority);
        }
    }
}
