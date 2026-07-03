#include<stdio.h>
int main()
{
    int n;
    printf("Enter Array size: ");
    scanf("%d",&n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of index %d: ",i);
        scanf("%d",&array[i]);
    }
    for (int i = 0,j=n-1; i < n/2; i++,j--)
    {
        int temp=array[i];
        array[i]=array[j];
        array[j]=temp;
    }
    printf("Reverse array\n");
    for (int i = 0; i <n; i++)
    {
        printf("%d\n",array[i]);
    }
    
    return 0;
}