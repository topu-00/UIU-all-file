#include<stdio.h>
int main()
{
    int n,count=0;
    printf("Enter a positive intiger number: ");
    scanf("%d",&n);
    if (n==0 || n==1)
    {
        printf("Not prime\n");
        return 0;
    }
    for (int i = 2; i <= n/2; i++)
    {
        if (n%i==0)
        {
            count++;
            break;
        }
        
    }
    if (count==1)
    {
        printf("Not prime\n");
    }
    else{
        printf("Prime\n");
    }
    return 0;
}