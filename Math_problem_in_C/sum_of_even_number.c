#include<stdio.h>
int main()
{
    int max,mini,n1,n2,sum=0;
    printf("Enter Number1: ");
    scanf("%d",&n1);
    printf("Enter Number2: ");
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
        if (i % 2 == 0)
        {
            sum+=i;
        }
        
    }
    printf("Sum Of Even numbers between %d and %d is:%d\n",mini,max,sum);
    return 0;
}