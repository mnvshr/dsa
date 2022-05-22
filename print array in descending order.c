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
    printf("Enter the marks of students in ascending order \n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    
}

void array_output(int a[], int n)
{
    printf("The marks of students in descending order are \n");
    for (int i = n-1; i >= 0; --i)
    {
        printf("%d\t", a[i]);
    }
    
}
