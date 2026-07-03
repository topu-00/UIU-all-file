#include <stdio.h>
int main()
{
    int n;
    int j;
    printf("Enter The 1st array index number:");
    scanf("%d", &n);
    printf("Enter The 2nd array index number:");
    scanf("%d", &j);
    int arr[n];
    int arr2[j];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the 1st array index %d Value:", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < j; i++)
    {
        printf("Enter the 2nd array index %d Value:", i);
        scanf("%d", &arr2[i]);
    }
    int mini, max;
    int sum = 0;
    if (n > j)
    {
        max = n;
        mini = j;
    }
    else
    {
        max = j;
        mini = n;
    }

    for (int i = 0; i < mini; i++)
    {
        sum = arr2[i] + arr[i];
        printf("sum=%d\n", sum);
    }
    // float avg=sum/n;
    // printf("sum=%.2f\n",avg);
    return 0;
}
