#include <stdio.h>

int main()
{
    int i, j, n;
    printf("Enter a Number:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d", i);
        }
        printf("\n");
    }
    for (int k = n - 1; k > 0; k--)
    {
        for (int x = 0; x < k; x++)
        {
            printf("%d", k);
        }
        printf("\n");
    }

    return 0;
}