#include<stdio.h>
#include<stdlib.h>

int input();
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void display();

struct node
{
    int info;
    struct node *next;
};

struct node *last = NULL;

int main()
{
    printf("- - - SINGLY LINKED LIST - - - \n");

    while (1)
    {
        printf("1. Insert at beginning \n");
        printf("2. Insert at end \n");
        printf("3. Insert at a specific position \n");
        printf("4. Delete at beginning \n");
        printf("5. Delete at end \n");
        printf("6. Delete at specific position \n");
        printf("7. Display list \n");
        printf("8. Exit \n");

        int n = input();

        if (n == 8)
        {
            break;
        }
        

        switch(n)
        {
            case 1:
            insert_beg();
            break;

            case 2:
            insert_end();
            break;

            case 3:
            insert_pos();
            break;

            case 4:
            delete_beg();
            break;

            case 5:
            delete_end();
            break;

            case 6:
            delete_pos();
            break;

            case 7:
            display();
            break;

            default:
            printf("Invalid choice \n");
            break;
        }
    }
    return 0;
}

int input()
{
    int n;

    printf("Enter your choice: ");
    scanf("%d", &n);

    return n;
}

void insert_beg()
{
    int value;

    printf("Enter the node you want to insert: ");
    scanf("%d", &value);

    struct node *new = (struct node *)malloc(sizeof(struct node*));

    if (last == NULL)
    {
        new -> info = value;
        new -> next = new;
        last = new;
    }

    else
    {
        new -> info = value;
        new -> next = last -> next;
        last -> next = new;
    }

    printf("\nNODE INSERTED\n\n");
}

void insert_end()
{
    int value;

    printf("Enter the node you want to insert: ");
    scanf("%d", &value);

    struct node *new = (struct node *)malloc(sizeof(struct node*));

    if (last == NULL)
    {
        new -> info = value;
        new -> next = new;
        last = new;
    }
    else
    {
        new -> info = value;
        new -> next = last -> next;
        last -> next = new;
        last = new;
    }

    printf("\nNODE INSERTED\n\n");
}

void insert_pos()
{
    int pos, value;

    struct node *new = (struct node *)malloc(sizeof(struct node *));
    struct node *previous = (struct node *)malloc(sizeof(struct node *));

    printf("Enter the position where you want to insert the node: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insert_beg();
    }
    else
    {
        printf("Enter the node you want to insert: ");
        scanf("%d", &value);

        previous = last;
        int count = 1;

        while (count <= pos - 1 && previous -> next != NULL)
        {
            previous = previous -> next;
            count++;
        }
        if (previous = last)
        {
            insert_end();
        }
        else
        {
            new -> next = previous -> next;
            previous -> next = new;
            new -> info = value;
        }
        printf("\nNODE INSERTED\n\n");
    }
}

void delete_beg()
{
    struct node *new;

    if (last == NULL)
    {
        printf("Underflow \n");
    }
    else if (last -> next == last)
    {
        free(last);
        last = NULL;
    }
    else
    {
        new = last -> next;
        last -> next = new -> next;
        new -> next = NULL;
        free(new);
    }
    printf("\nNODE DELETED");
}

void delete_end()
{
    struct node *new = (struct node *)malloc(sizeof(struct node*));
    struct node *previous = (struct node *)malloc(sizeof(struct node *));

    if (last == NULL)
    {
        printf("Underflow \n");
    }
    else if (last -> next == last)
    {
        free(last);
        last = NULL;
    }
    else
    {
        new = last -> next;

        while (new -> next != last)
        {
            new = new -> next;
        }

        new -> next = last -> next;
        last -> next = NULL;
        free(last);
        last = new;
    }
}

void delete_pos()
{
    int pos;

    struct node *new = (struct node *)malloc(sizeof(struct node*));
    struct node *previous = (struct node *)malloc(sizeof(struct node *));

    printf("Enter the position from where you want to delete: ");
    scanf("%d", &pos);

    new = last -> next;
    previous = NULL;

    if (last = NULL)
    {
        printf("\n Underflow \n");
    }
    else if (pos == 1)
    {
        last -> next = new -> next;
        new -> next = NULL;
        free(new);
    }
    else
    {
        for (int i = 0; i <= pos - 1; i++);
        {
            previous = new;
            new = new -> next;
        }
        if (new == last)
        {
            previous -> next = last -> next;
            last = previous;
        }
        previous -> next = new -> next;
        new -> next = NULL;
        free(new);
    }
}

void display()
{
    struct node *new1 = last -> next;

    while (new1 != last)
    {
        printf("%d -> ", new1 -> info);
        new1 = new1 -> next;
    }
    printf("%d", last -> info);
    printf("\n");
}
