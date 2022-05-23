#include <stdio.h>
#include <stdlib.h>

#define capacity 10

int input();
void push(int);
int isFull();
int pop();
int isEmpty();
void display();

int stack[capacity], top = -1, item;

void main()
{
    while (1)
    {
        printf("- - - STACKS MENU - - - \n");

        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Display \n");
        printf("4. Exit \n");

        printf("Enter your choice: ");
        int n = input();

        switch (n)
        {
        case 1:
        printf("Enter the item you want to push: ");
        item = input();
        push(item);
        break;
        
        case 2:
        item = pop();

        if (item == 0)
        {
            printf("Stack underflow \n");
        }
        else
        {
            printf("%d popped \n", item);
        }
        
        break;

        case 3:
        display();
        break; 

        case 4:
        exit(0); 

        default:
        printf("Invalid Input \n\n");
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

void push(int element)
{
    if (isFull())
    {
        printf("Stack overflow \n");
    }
    else
    {
        top++;
        stack[top] = element;
        printf("%d pushed \n", element);
    }
    
}

int isFull()
{
    if (top == capacity - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop()
{
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        return stack[top--];
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty \n");
    }
    else
    {
        printf("Stack elements are: \n");

        for (int i = 0; i <= top; i++)
        {
            printf("Stack element %d : %d \n", i, stack[i]);
        }
    }
}
