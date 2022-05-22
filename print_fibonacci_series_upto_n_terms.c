#include<stdio.h>

void fibonacci(int n);

void fibonacci(int n)
{
    int a = 0, b = 1, c;

    for (int i = 0; i < n; ++i)
    {
        printf("%d \t", a);
        c = a + b;
        a = b;
        b = c;
    }
    
}

int main()
{
    int n;
    
    printf("Enter the number of terms to print: ");
    scanf("%d", &n);

    fibonacci(n);
}
