#include<stdio.h>
#include<limits.h>
int main()
{
    int number,n,total=0,avg;
    int max=INT_MIN, mini=INT_MAX;
    printf("Enter a Number, how many you want as input : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&number);
        total+=number;
        if (number>max)
        {
            max=number;
        }
        if (number<mini)
        {
            mini=number;
        }
        
    }
    printf("Maximum Number: %d\n",max);
    printf("Minimum Number: %d\n",mini);
    printf("Average: %d\n",total/n);
    return 0;
}