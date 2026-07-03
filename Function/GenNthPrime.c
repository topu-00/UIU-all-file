#include <stdio.h>
void isPrime(int m)
{
    int count = 0;
    for (int j = 2; j <= m / 2; j++)
    {
        if (m % j == 0)
        {
            count++;
            break;
        }
    }
    if (count == 0)
    {
        printf("%d ", m);
    }
}
void GeneratePrime(int x)
{
    int i;
    for (i = 2; i < x; i++)
    {
        isPrime(i);
    }
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    GeneratePrime(n);
    printf("\n");
    return 0;
}