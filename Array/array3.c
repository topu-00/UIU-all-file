#include<stdio.h>
int main()
{
    int array[100];
    for (int i = 0; i < 3; i++)// This loop Use for store the value of array.
    {
        printf("Enter the value of index %d : ",i);
        scanf("%d",&array[i]);
    }
    for (int i = 0; i < 3; i++)// This loop Use for print the value of array.
    {
        printf("Index %d : %d\n",i,array[i]);
    }
    
    return 0;
}