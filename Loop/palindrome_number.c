#include<stdio.h>
int main()
{
    int n;
    int mod,rev=0;
    printf("Enter a integer number: ");
    scanf("%d",&n);
    int temp=n;
    while(n!=0)
    {
        mod=n%10;
        n/=10;
        rev=rev*10+mod;
    }
    if (temp==rev)
    {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}