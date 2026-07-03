/*
WAP that will take inputs of two 3 x 3 sized matrix into two 2D array,
suppose A and B.Now do C = A * B (multiplication). Finally display all the
elements from matrix / 2D array C.
*/
#include <stdio.h>
int main()
{
    int array_1[3][3];
    int array_2[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &array_1[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &array_2[i][j]);
        }
    }
    int array_3[3][3];
    int a = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a = a + (array_1[i][j] * array_2[j][i]);
        }
        for (int k = 0; k < 3; k++)
        {
            array_3[i][k] = a;
        }
        a = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", array_3[i][j]);
        }
        printf("\n");
    }
    return 0;
}