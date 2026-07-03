/*WAP that will take 9 integers into a 3 by 3 array (2D) and
show them as traditional matrix view.*/
#include <stdio.h>
int main()
{
    int array[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d",array[i][j]);
        }
        printf("\n");
    }
    return 0;
}