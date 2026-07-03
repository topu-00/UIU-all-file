#include <stdio.h>
//problem 12
int main() {
    int n,sum=0;
    int k=1;
    printf("Enter a Number:");
    scanf("%d", &n);
    printf("0,1,");
    for (int i =1; i <= n; i++) 
    {
        sum+=k;
        printf("%d,",sum);
        int temp=sum;
        sum=k;
        k=temp;
    }
    printf("\n");
    return 0;
}