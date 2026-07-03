#include <stdio.h>
#include <limits.h>
int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of index %d: ", i);
        scanf("%d", &array[i]);
    }
    int max = INT_MIN;
    int mini = INT_MAX;
    int max_index, mini_index;
    for (int i = 0; i < n; i++)
    {
        max = max > array[i] ? max : array[i];
        if (max == array[i])
        {
            max_index = i;
        }
    }
    printf("Max: %d , Max Index: %d\n", max, max_index);
    for (int i = 0; i < n; i++)
    {
        mini = mini < array[i] ? mini : array[i];
        if (mini == array[i])
        {
            mini_index = i;
        }
    }
    printf("Mini: %d , Mini Index: %d\n", mini, mini_index);
    return 0;
}