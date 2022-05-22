#include<stdio.h>

void array_input(int a[], int n);
void array_output(int a[], int n);

int main()
{
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    int a[n];
    
    array_input(a, n);
    array_output(a, n);

    return 0;
}

void array_input(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("\nEnter the marks of student %d: ", i);
        scanf("%d", &a[i]);
    }
}

void array_output(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("\nThe marks of student %d are: %d",i, a[i]);
    }
}
