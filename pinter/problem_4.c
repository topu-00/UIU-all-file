#include <stdio.h>
int main()
{
    int x = 10, y = 20, temp;
    int *ptr_x, *ptr_y;
    ptr_x = &x;
    ptr_y = &y;
    temp = *ptr_x;
    *ptr_x = *ptr_y;
    *ptr_y = temp;
    printf("X = %d\nY = %d\n", x, y);
    return 0;
}