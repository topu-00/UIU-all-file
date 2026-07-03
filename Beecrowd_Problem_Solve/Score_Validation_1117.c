#include<stdio.h>
int main()
{
    int count=0;
    double n,sum=0;
    
    for (int i = 0; ; i++)
    {
        scanf("%lf",&n);
        if (n>=0 && n<=10)
        {
        sum+=n;
        count++;
        if (count==2)
        {
            break;
        }
        }
        else{
            printf("nota invalida\n");
        }
    }
    printf("media = %.2lf\n",sum/2);
    return 0;
}