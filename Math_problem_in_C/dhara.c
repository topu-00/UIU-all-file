#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,result=1;
    printf("Enter a Number:");
    scanf("%d",&n);
    for ( i = 1; i <= n; i++)
    {
        result=pow(n,i);
        printf("%d\t",result);
    }
    printf("\n");
    return 0;
}