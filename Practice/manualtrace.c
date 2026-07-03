// (Batch 193) pronlem 2(A);
#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d", &b);
    printf("Start\n");
    if (b <= 5)
        printf("Hello\n");
    else if (b > 5)
        printf("World\n");
    else if ((b >= 2) && (b < 10))
        printf("UIU\n");
    else if ((b > 2) || (b <= 10))
        printf("CSE\n");
    else
        printf("Error\n");
    printf("Stop");
    return 0;
}