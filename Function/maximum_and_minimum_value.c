#include <stdio.h>
#include <limits.h>
int minimum()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter The value of index %d: ", i);
        scanf("%d", &array[i]);
    }
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = mini < array[i] ? mini : array[i];
    }
    return mini;
}
int main()
{
    printf("Minimum Value: %d\n", minimum());
    return 0;
}