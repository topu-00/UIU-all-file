// problem 2.
#include <stdio.h>
#include <math.h>
int main()
{
    int n, j = 1;
    int sum = 1;
    int total_sum = 0;
    printf("Enter a Number:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        total_sum += sum;
        int temp = j + (pow(10, i));
        j = temp;
        sum = sum + temp;
    }
    printf("Sum of the series : %d\n", total_sum);
    return 0;
}