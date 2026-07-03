#include<stdio.h>
int main()
{
    int arr[10];
    for ( int i = 0; i < 10; i++)
    {
        printf("Entr the valu of Index: %d :",i);
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}
