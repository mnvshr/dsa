#include <stdio.h>

unsigned long fact_iter(int a);
unsigned long fact_rec(int b);

int main()
{
    int n, temp;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Factorial of %d by iteration is %lu \n", n, fact_iter(n));
    printf("Factorial of %d by recurrsion is %lu", n, fact_rec(n));
    return 0;
}

unsigned long fact_iter(int n)
{
    unsigned long f = 1;
    for(int i=1; i<=n; ++i) {
        f = f * i;
    }
    return f;
}

unsigned long fact_rec(int n)
{
    if(n>=1)
    return n*fact_rec(n-1);
    else
    return 1;
}
