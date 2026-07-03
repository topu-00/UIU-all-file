#include <stdio.h>
int main()
{
    printf("Enter the array size:");
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter The valu of index %d :", i);
        scanf("%d", &array[i]);
    }
    for (int i = 0, k = n - 1; i < n; i++, k--)
    {
        printf("%d\n", array[k]);
    }
    return 0;
}
