#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    int *ptr;
    ptr = &array[0];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr);
        ptr++;
    }
    ptr = &array[0];
    printf("OutPut:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", *ptr);
        ptr++;
    }
    return 0;
}