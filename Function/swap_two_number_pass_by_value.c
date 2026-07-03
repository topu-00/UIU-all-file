#include <stdio.h>
void swap(int n1, int n2)
{
    n1 = n1 + n2;
    n2 = n1 - n2;
    n1 = n1 - n2;
    printf("Value in func: %d   %d\n", n1, n2);
}
int main()
{
    int a, b;
    printf("Enter a Value for A: ");
    scanf("%d", &a);
    printf("Enter a Value for B: ");
    scanf("%d", &b);
    swap(a, b);
    return 0;
}
