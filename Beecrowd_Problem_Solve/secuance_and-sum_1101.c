#include<stdio.h>
int main()
{
    int max,mini,n1,n2,sum=0;
    scanf("%d",&n1);
    scanf("%d",&n2);
    if (n1>=n2)
    {
        max=n1;
        mini=n2;
    }
    else{
        max=n2;
        mini=n1;
    }
        for (int i = mini; i <= max; i++)
            {
                if (i<=0 || max<=0)
                {
                    break;
                }
                
                sum+=i;
                printf("%d ",i);
            }
            if (sum>0)
            {
                printf("Sum=%d\n",sum);
            }
    return 0;
}