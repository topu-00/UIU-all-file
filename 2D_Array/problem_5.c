/*WAP that will take the size of an identity matrix from the user
and generate the identity matrix into a 2D array. Finally display it.
Reference:http://en.wikipedia.org/wiki/Identity_matrix
*/
#include <stdio.h>
int main()
{
    int n;
    printf("Enter a value for matrix: ");
    scanf("%d", &n);
    int array[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i==j)
            {
                array[i][j]=1;
            }
            else{
                array[i][j]=0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    return 0;
}