#include <stdio.h>
int fact(int x)
{
    int fact = 1;
    for (int i = 1; i <= x; i++)
    {
        fact *= i;
    }

    return fact;
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("factorial: %d\n",fact(n));
    return 0;
}