/*
WAP that will take inputs of m x n sized matrix into a 2D array and
find the maximum element with index locationfrom that matrix.
*/
#include <stdio.h>
#include <limits.h>
int main()
{
    int m, n;
    printf("Enter the array size(m * n): ");
    scanf("%d%d", &m, &n);
    int array[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    int max = INT_MIN;
    int location1,location2;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i][j] > max)
            {
                max=array[i][j];
                location1=i;
                location2=j;
            }
        }
    }
    printf("Max:%d\nLocation:[%d][%d]\n",max,location1,location2);
    return 0;
}