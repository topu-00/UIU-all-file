// Not compleate.
#include <stdio.h>
#include <limits.h>
void minimum()
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
    int temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (mini > array[j])
            {
                mini = array[j];
                temp = array[i];
                array[i] = mini;
                array[j] = temp;
            }
        }
    }
    for (int x = 0; x < n; x++)
    {
        printf("%d\n", array[x]);
    }
}
int main()
{
    minimum();
    return 0;
}