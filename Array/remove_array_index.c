#include <stdio.h>
int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of index %d: ",i);
        scanf("%d",&array[i]);
    }
    int position;
    printf("Enter which position you want to delet:");
    scanf("%d",&position);
    for (int i = position; i < n; i++)
    {
        array[i]=array[i+1];
    }
    n--;
    for (int i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}