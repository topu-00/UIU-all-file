// problem 5(B).
#include <stdio.h>
void doSomething(int *num1, int *num2, float sum[])
{

    sum[0] = *num1 + *num2;

    sum[1] = *num1 - *num2;

    sum[2] = *num1 * *num2;

    sum[3] = (float)*num1 / (float)*num2;
}
int main()
{
    int num1, num2;
    float sum[4];
    scanf("%d%d", &num1, &num2);
    doSomething(&num1, &num2, sum);
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            printf("Sum=%.2f\n", sum[i]);
        }
        else if (i == 1)
        {
            printf("Substraction=%.2f\n", sum[i]);
        }
        else if (i == 2)
        {
            printf("Multiplication=%.2f\n", sum[i]);
        }
        else if (i == 3)
        {
            printf("Division= %.2f\n", sum[i]);
        }
    }

    return 0;
}