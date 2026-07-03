#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        double x, y;
        scanf("%lf%lf", &x, &y);
        if (y == 0)
        {
            printf("divisao impossivel\n");
        }
        else
        {
            printf("%.1lf\n", x / y);
        }
    }
    return 0;
}