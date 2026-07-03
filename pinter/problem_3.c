#include <stdio.h>

int main()
{
    int x = 10, y = 20, sum;
    int *ptr_x, *ptr_y;
    ptr_x = &x;
    ptr_y = &y;
    sum = *ptr_x + *ptr_y;
    printf("Sum = %d\n", sum);
    return 0;
}