// Beecrowd Accepted.
#include<stdio.h>
int main()  
{
    int max,mini,n1,n2,sum=0,i=1;
        for (int i=1; ; i++)
        {
            scanf("%d%d",&n1,&n2);
            if (n1<=0 || n2<=0)
                {
                    break;
                }
            
            else if (n1>=n2)
                    {
                        max=n1;
                        mini=n2;
                    }
            else
                {
                    max=n2;
                    mini=n1;
                }
                for (int j = mini; j <= max; j++)
                {
                    sum+=j;
                    printf("%d ",j);
                }
                printf("Sum=%d\n",sum);
                sum=0;
        }
    return 0;
}