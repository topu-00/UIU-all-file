// This program have a bug.
#include<stdio.h>
#include<limits.h>
int main()
{
int n;
int max=0,mini=INT_MIN;
printf("Enter The size of array:");
scanf("%d",&n);
int array[n];
int i;
for (i = 0; i <n ; i++)
{
    printf("Enter The elements of array:");
    scanf("%d",&array[i]);
    if (mini<array[i])
    {
        max=array[i];
    }
}
int m;
int x;
printf("Enter The number to search for:");
scanf("%d",&m);
if (max<m)
{
    printf("%d not found.\n",m);
    return 0;
}

    printf("Enter The number to replace with:");
        scanf("%d",&x);
for (int i = 0; i < n; i++)
{
    if (array[i]==m)
    {
        array[i]=x;
    }
}
printf("Modified array:");
for (int i = 0; i < n; i++)
{
    printf("%d",array[i]);
}
printf("\n");
    return 0;
}