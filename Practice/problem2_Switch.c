#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
    case 2:
        printf("CSE\n");
        break;
    case 3:
        printf("UIU\n");
        break;
    default:
    if (n>3)
    {
        printf("Bye\n");
    }
        break;
    }
    return 0;
}