#include<stdio.h>
int x=10;
int main()
{
    int x=15;

    printf("%d\n",x);
    {
        extern int x;
        printf("%d\n",x);
    }
    return 0;
}