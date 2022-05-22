#include<stdio.h>

void check_palindrome(int n);

void check_palindrome(int n)
{
    int rev = 0, rem, original;
    
    original = n;

    while (n != 0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }

    if (original == rev)
    {
        printf("%d is a palindrome", original);
    }
    else
    {
        printf("%d is not a palindrome", original);
    }
}

int main()
{
    int n;

    printf("Enter the number to check: ");
    scanf("%d", &n);

    check_palindrome(n);
}
