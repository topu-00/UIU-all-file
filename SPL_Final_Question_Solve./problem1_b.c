// problem 1(B).
#include <stdio.h>
int digitSum(int num)
{
    int sum = 0;
    for (; num != 0;)
    {
        int rese = num % 10;
        sum += rese;
        num = num / 10;
    }
    return sum;
}
int digitPosition(int num)
{
    printf("%d\n", num);
    return 0;
}
int main()
{
    int number;
    printf("Enter a Number: ");
    scanf("%d", &number);
    int sum = digitSum(number);
    digitPosition(sum);
    return 0;
}