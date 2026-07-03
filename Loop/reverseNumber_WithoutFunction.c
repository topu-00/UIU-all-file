#include<stdio.h>
int main()
{
    int num,rev=0,mod;
    printf("Enter a Number: ");
    scanf("%d",&num);
    while(num!=0)
    {
        mod=num%10;
        num=num/10;
        rev=rev*10+mod;
    }
    printf("Revers Number: %d\n",rev);
return 0;
}