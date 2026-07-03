#include <stdio.h>
int factorial(int n)
{
    int fact = 1;
    for (int i = n; i > 0; i--)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int n, r, nCr;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of r: ");
    scanf("%d", &r);
    if (n < r)
    {
        printf("wrong input:'r' can't be large from 'n'\n");
        return 0;
    }
    nCr = (factorial(n)) / (factorial(r) * factorial(n - r));
    printf("%d\n", nCr);
    return 0;
}