#include <stdio.h>
void printRevOrd(int array[], int n)
{
    printf("Value from func:");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the array size:");
    scanf("%d", &n);
    int array[n];
    printf("Enter the index value: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printRevOrd(array, n);
    return 0;
}
