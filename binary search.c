#include<stdio.h>
#include<conio.h>

void read(int a[], int size)
{
    printf("Enter the values in ascending order\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
}

int binarySearch(int a[], int size, int key)
{
    int left = 0, right = size - 1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (a[mid] == key)
        {
            printf("Element found at %d", mid);
            break;
        }
        else if (a[mid] > key)
        {
            right = mid - 1;
        }
        else if (a[mid] < key)
        {
            left = mid + 1;
        }
        if (left > right)
        {
            printf("Invalid");
        }
        
    }
}

int main()
{
    int size, key;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int a[size];

    read(a, size);

    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    binarySearch(a, size, key);

    getch();
}
