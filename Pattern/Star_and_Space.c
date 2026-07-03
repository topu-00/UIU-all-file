#include <stdio.h>
//problem 9
int main()
{
    printf("Enter a number:");
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        if (i%2!=0)
        {
            for (int k = 1; k <=n; k++)
            {
                printf("*");
            }
            printf("\n");
        }
        else{
            for (int k = 1; k <=n; k++)
            {
                if (k==1 || k==n)
                {
                    printf("*");
                }
                else{
                    printf("_");
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}