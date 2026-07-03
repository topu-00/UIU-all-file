#include<stdio.h>
int main()
{
    for (int i = 1,j=60; j >=0; i+=3,j-=5)
    {
        printf("I=%d J=%d",i,j);
        printf("\n");
    }
    
    return 0;
}