#include <stdio.h>
#include <limits.h>
int main()
{
    int x = 7, y = 5;
    for (int i = 1; i <= 9; i += 2)
    {
        for (int j = x; j >= y; j--)
        {
            printf("I=%d J=%d\n", i, j);
        }
        x = x + 2;
        y = y + 2;
    }
    return 0;
}