/*
    Name: Mahmudul Hasan Topu ;
    ID: 0112330164 ; 
    Name: Sadika Binti Noor ;
    ID: 0112330453 ;
*/
#include <stdio.h>
#include <limits.h>
int main()
{
    int array[3][3];
    printf("\n-----InPut-----\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    int max = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (max < array[i][j])
            {
                max = array[i][j];
            }
        }
    }
    int max2 = INT_MIN;
    int index_i, index_j;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (max == array[i][j])
            {
                continue;
            }
            else if (max2 < array[i][j])
            {
                max2 = array[i][j];
                index_i=i;
                index_j=j;
            }
        }
    }
    printf("\n-----OutPut-----\n");
    printf("2nd_Max: %d\n", max2);
    printf("Index:[%d,%d]\n",index_i,index_j);
    return 0;
}