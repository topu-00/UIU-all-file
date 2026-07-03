#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter The Value of a:");
    scanf("%d", &a);
    printf("Enter the value of b:");
    scanf("%d", &b);
    int max = a > b ? a : b;
    for (int i = 0; ; i++)
    {
        if (max % a == 0 && max % b == 0)
        {
            break;
        }
        max++;
    }
    int GCD = (a * b)/max;
    printf("GCD of %d and %d is: %d\n",a,b,GCD);
    printf("LCM of %d and %d is: %d\n",a,b,max);
    return 0;
}