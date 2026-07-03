/*
WAP that will take inputs of two m x n sized matrix into two 2D array, suppose A and B.
Now do C = A + B. Finally display all the elements from matrix / 2D array C.
*/
#include <stdio.h>
int main()
{
    int m, n;
    printf("Enter The matrix size: ");
    scanf("%d%d", &m, &n);
    int array_1[m][n];
    int array_2[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &array_1[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &array_2[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", array_1[i][j] + array_2[i][j]);
        }
        printf("\n");
    }
    return 0;
}