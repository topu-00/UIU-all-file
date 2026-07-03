// reverse_the_digits_of_an_input_integer(with function)
#include <stdio.h>
int reverseNum(int num)
{
    int reversNum = 0;
    while (num != 0)
    {
        int digit = num % 10;
        reversNum = reversNum * 10 + digit;
        num = num / 10;
    }
    return reversNum;
}
int main()
{
    int numm;
    printf("Enter a number: ");
    scanf("%d", &numm);
    int result = reverseNum(numm);
    printf("%d\n", result);
    return 0;
}