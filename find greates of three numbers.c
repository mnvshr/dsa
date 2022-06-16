#include<stdio.h>

int func_greatest(int, int, int);

int func_greatest(int n1, int n2, int n3) 
{
    int greatest;
    if (n1 >= n2 && n1 >= n3)
    {
        return n1;
    }
    
    if (n2 >= n1 && n2 >= n3)
    {
        return n2;
    }

    if (n3 >= n1 && n3 >= n2)
    {
        return n3;
    }

    // Using ternary operator:
    // return((n1 > n2 && n1 > n3) ?n1: (n2 > n3) ?n2: n3);
}

int main()
{
    int n1, n2, n3;

    printf("Enter number 1: ");
    scanf("%d", &n1);

    printf("Enter number 2: ");
    scanf("%d", &n2);

    printf("Enter number 3: ");
    scanf("%d", &n3);

    int result = func_greatest(n1, n2, n3);

    printf("%d is the greatest", result);

    return 0;
}
