#include<stdio.h>

void array_input(int a[], int n);
void largest(int a[], int n);

int main()
{
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    int a[n];

    array_input(a, n);
    largest(a, n);

    return 0;
}

void array_input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the marks of student %d: ", i);
        scanf("%d", &a[i]);
    } 
}

void largest(int a[], int n)
{
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    printf("Highest marks: %d", max);
}
