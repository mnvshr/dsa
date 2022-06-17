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
void display_rev();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *last = NULL;

int main()
{
    printf("- - - DOUBLY LINKED LIST - - - \n");

        while (1)
    {
        printf("\n1. Insert at beginning \n");
        printf("2. Insert at end \n");
        printf("3. Insert at a specific position \n");
        printf("4. Delete at beginning \n");
        printf("5. Delete at end \n");
        printf("6. Delete at specific position \n");
        printf("7. Display list \n");
        printf("8. Display in reverse \n");
        printf("9. Exit \n");

        int n = input();

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
            delete_beg(head);
            break;

            case 5:
            delete_end(last);
            break;

            case 6:
            delete_pos(head);
            break;

            case 7:
            display(head);
            break;

            case 8:
            display_rev(last);
            break;

            case 9:
            exit(0);

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
    struct node *ptr;
    struct node *temp = head;

    int item;

    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter the value to insert: ");
        scanf("%d", &item);

        if (head == NULL)
        {
            ptr -> next = NULL;
            ptr -> prev = NULL;
            ptr -> data = item;
            head = ptr;
            last = ptr;
        }
        else
        {
            ptr -> data = item;
            ptr -> prev = NULL;
            ptr -> next = head;
            head -> prev = ptr;
            head = ptr;

            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            last = temp;
        }
        printf("Node inserted \n");
    }
}

void insert_end()
{
    int item;

    printf("Enter the value you want to insert: ");
    scanf("%d", &item);

    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = last;
    temp -> data = item;

    if (last == NULL)
    {
        printf("No node exists\n");
    }
    else
    {
        temp -> next = NULL;
        temp -> prev = last;
        last -> next = temp;
        last = temp;
        printf("Node inserted\n");
    }
}

void insert_pos()
{
    int pos, item;

    printf("Enter the value: ");
    scanf("%d", &item);

    printf("Enter the position where you want to insert: ");
    scanf("%d", &pos);

    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = head, p;
    temp -> data = item;

    if (head == NULL)
    {
        printf("Node does not exist\n");
    }
    else if (pos == 1)
    {
        temp -> prev = NULL;
        temp -> next = head;
        head -> prev = temp;
        head = temp;
        printf("Node inserted");
    }
    else
    {
        for (int i = 2; i < pos; i++)
        {
            if (ptr -> next != NULL)
            {
                ptr = ptr -> next;
            }
        }
        ptr -> next -> prev = temp;
        temp -> next = ptr -> next;
        temp -> prev = ptr;
        ptr -> next = temp;
        printf("Node inserted\n");
    }
}

void delete_beg(struct node *p)
{
    struct node *ptr = p;

    if (p == NULL)
    {
        printf("List doesnt exist\n");
    }
    else if (p -> next == NULL && p -> prev == NULL)
    {
        free(ptr);
        head = NULL;
        last = NULL;
        printf("First node deleted\n");
    }
    else
    {
        ptr -> next -> prev = NULL;
        head = ptr -> next;
        ptr -> next = NULL;
        ptr -> prev = NULL;
        free(ptr);
        printf("Node deleted\n");
    }
}

void delete_end(struct node *p)
{
    struct node *ptr = p;

    if (p == NULL)
    {
        printf("List doesnt exist\n");
    }
    else
    {
        last = ptr -> prev;
        ptr -> prev -> next = NULL;
        ptr -> prev = NULL;
        free(ptr);
        printf("Deleted from end\n");
    }
}

void delete_pos(struct node *p)
{
    int pos;

    printf("Enter the position from where you want to delete the node: ");
    scanf("%d", &pos);

    struct node *ptr, *current;

    ptr = p;

    if (pos == 1)
    {
        free(ptr);
        head = NULL;
        last = NULL;
        printf("First node deleted\n");
    }
    else
    {
        for (int i = 2; i <= pos; i++)
        {
            current = ptr;
            ptr = ptr -> next;
        }
        current -> next = ptr -> next;
        ptr -> next -> prev = current;
        ptr -> next = NULL;
        ptr -> prev = NULL;
        free(ptr);
        printf("Node deleted\n");
    }
}

void display(struct node *p)
{
    struct node *ptr = p;
    while (p != NULL)
    {
        printf("%d -> ", p -> data);
        ptr = p;
        p = p -> next;
    }
}

void display_rev(struct node *p)
{
    struct node *ptr = p;

    printf("Reverse : ");

    while (p != NULL)
    {
        printf("%d -> ", ptr -> data);
        ptr = p -> prev;
        p = p -> prev;
    }
}
