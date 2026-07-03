#include <stdio.h>

int main()
{
    int x = 10, y = 20, z = 30;
    int *ptr;
    ptr = &x;
    printf("Value of X= %d\n", *ptr);
    ptr = &y;
    printf("Value of y= %d\n", *ptr);
    ptr = &z;
    printf("Value of z= %d\n", *ptr);
    return 0;
}
