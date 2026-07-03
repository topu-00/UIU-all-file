#include <stdio.h>
int main()
{
    int max;
    int mini;
    int x, y;
    printf("Enter The Value of X:");
    scanf("%d", &x);
    printf("Enter The Value of Y:");
    scanf("%d", &y);
    if (x > y)
    {
        max = x;
        mini = y;
    }
    else
    {
        max = y;
        mini = x;
    }
    for (int i = mini; i < max; i++)
    {
        if (x > y)
        {
            printf("%d\t", x * x);
            x--;
        }
        else
        {
            printf("%d\t", x * x);
            x++;
        }
    }
    printf("Reached!\n");
    return 0;
}
