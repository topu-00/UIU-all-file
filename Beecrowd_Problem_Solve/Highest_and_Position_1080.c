#include<stdio.h>
#include<limits.h>
int main()
{
    int array[100];
    for (int i = 0; i < 100; i++)
    {
        scanf("%d",&array[i]);
    }
    int max=INT_MIN;
    int max_index;
    for (int i = 0; i < 100; i++)
    {
        if (max<array[i])
        {
            max=array[i];
            max_index=i;
        }
    }
    printf("%d\n%d\n",max,max_index+1);
    return 0;
}