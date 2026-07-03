//Write a program (WAP) that will calculate the result for the first Nth terms of the following series. 
//[In that series sum, dot sign (.) means multiplication]
//1*1*2 + 2*2*3 + 3*3*4 + 4*4*5 + …….
#include<stdio.h>
#include<math.h>
int main()
{
    int n,series,sum=0;
    printf("Enter a number which define wher the series stop: ");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        series= pow(i,2)*(i+1);
        sum+=series;
        printf("%d+",series);
    }
    printf("\n");
    printf("Sum= %d\n",sum);
    return 0;
}