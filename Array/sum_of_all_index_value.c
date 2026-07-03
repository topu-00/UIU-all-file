#include<stdio.h>
int main()
{
    int n;
    printf("Enter The array index number:");
    scanf("%d",&n);
    int arr[n];
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the index %d Value:",i);
        scanf("%d",&arr[i]);
    }
    for (int i = n-1; i >=0 ; i--)
    {
        arr2[n-1-i]=arr[i];
    }
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        if (i%2==0)
        {
            sum=sum+arr2[i];
        }
    }
    printf("sum=%d\n",sum);
    return 0;
}
