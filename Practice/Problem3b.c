#include <stdio.h>
int main()
{
    float n;
    int count = 0;
    float avg;
    float sum = 0;
    for (int i = 0;; i++)
    {
        printf("Enter the value of N: ");
        scanf("%f", &n);
        if (n > 0)
        {
            sum += n;
            count++;
        }
        if (count > 3)
        {
            break;
        }
    }
    avg=sum/4;
    printf("%.2f\n", avg);
    return 0;
}