#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter the valu of A:");
    scanf("%d",&a);
    printf("Enter the valu of B:");
    scanf("%d",&b);
    printf("Enter the valu of C:");
    scanf("%d",&c);
    printf("%d\n",(a+b)<=80? 1 : 0);
    printf("%d\n", !(a+b) ? 1 : 0);
    printf("%d\n",c!=0 ? 1 : 0);
    return 0;
}