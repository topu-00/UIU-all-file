#include <stdio.h>
#include <limits.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i, x,in_count=0,out_count=0;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&x);
    if (x>=10 && x<=20)
    {
        in_count++;
    }
    else{
        out_count++;
    }
    }
    printf("%d in\n%d out\n",in_count,out_count);
    return 0;
}