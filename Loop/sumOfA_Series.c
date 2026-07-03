// Write a program (WAP) that will give the sum of first Nth terms for the following series.
// 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, …….
#include <stdio.h>
int main()
{
    int n, j = 0, sum1 = 0, temp = 0, sum2 = 0, sum = 0;
    printf("Enter how many number you want to do suma: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            temp = i;
            i = i - (i + i);
            printf("%d,", i);
            sum1 += i;
            i = temp;
        }
        else
        {
            printf("%d,", i);
            sum2 += i;
        }
        sum += sum1 + sum2;
        sum1 = 0;
        sum2 = 0;
    }
    printf("\n");
    printf("Sum= %d\n", sum);

    return 0;
}