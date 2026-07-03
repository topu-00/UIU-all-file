#include <stdio.h>
int main()
{
    int x, y;
    int max, mini, sum = 0;
    scanf("%d%d", &x, &y);
    max = x > y ? x : y;
    mini = x < y ? x : y;
    for (int i = mini; i <= max; i++)
    {
        if (i % 13 != 0)
        {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
