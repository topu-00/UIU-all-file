#include <stdio.h>
int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of array %d: ", i);
        scanf("%d", &array[i]);
    }
    int j;
    for (int i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
            {
                for (int i = j; i < n; i++)
                {
                    array[i] = array[i + 1];
                }
                n--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}