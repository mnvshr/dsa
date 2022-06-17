#include<stdio.h>
#include<conio.h>

void read_arr(int roll[], int size);
int linearSearch(int roll[], int size, int target);

int main()
{
    int size, target;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    int roll[size];

    printf("Enter the roll no. of students\n");

    read_arr(roll, size);

    printf("Enter the roll no. to search: ");
    scanf("%d", &target);

    int result = linearSearch(roll, size, target);

    (result == -1) ? printf("Roll no. doesnt exist") : printf("Roll no. present at index %d", result);

    getch();
}

void read_arr(int roll[], int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &roll[i]);
    }
}

int linearSearch(int roll[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (roll[i] == target)
        {
            return i;
        }
    }
    return -1;
}
