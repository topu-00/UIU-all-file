#include <stdio.h>
int main()
{
    int x = 5;
    int *ptr;
    ptr = &x;
    printf("Value of X= %d\n", x);
    printf("Location of X= %u\n", &x);
    printf("Location of X= %u\n", ptr);
    printf("Value of X= %d\n", *ptr);
    printf("Location of pointer= %u\n", &ptr);
    return 0;
} 