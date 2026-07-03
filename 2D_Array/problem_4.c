/*WAP that will take inputs of a n sized square matrix into a 2D array.
Now show all the elements of its two diagonals.
Reference: http://en.wikipedia.org/wiki/Main_diagonal
*/
#include <stdio.h>
int main()
{
    int n;
    printf("Enter a value for square matrix:");
    scanf("%d", &n);
    int array[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    printf("Major diagonal: ");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", array[j][j]);
    }
    printf("\n");
    printf("Minor diagonal: ");
    for (int j = n - 1,i=0; j >= 0; j--,i++)
    {
        printf("%d ", array[i][j]);
    }
    printf("\n");
    return 0;
}