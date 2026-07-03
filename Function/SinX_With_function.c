#include <stdio.h>
#include <math.h>
int factorial(int n)
{
    int fac = 1;
    for (int i = n; i > 0; i--)
    {
        fac *= i;
    }
    return fac;
}
int main()
{
    float x, sinx = 0;
    printf("Enter the value of X: ");
    scanf("%f", &x);
    for (int i = 1, j = 0; i <= 11; i += 2, j++)
    {
        if (j % 2 == 0)
        {
            sinx = sinx + ((pow(x, i)) / (factorial(i)));
        }
        else
        {
            sinx = sinx - ((pow(x, i)) / (factorial(i)));
        }
    }
    printf("%.3f\n", sinx);
    return 0;
}