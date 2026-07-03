/*WAP that will take (m x n) integers into a m by n array (2D)
and print them both row-wise and column-wise.*/
#include <stdio.h>
int main()
{
    int m, n;
    printf("Enter how many row you want: ");
    scanf("%d", &m);
    printf("Enter how many column you want: ");
    scanf("%d", &n);
    int array[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    printf("Row-wise: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", array[i][j]);
        }
    }
    printf("\n");
    printf("Column-wise: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", array[j][i]);
        }
    }
    printf("\n");
    return 0;
}