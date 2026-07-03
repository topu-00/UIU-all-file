#include<stdio.h>
#include<limits.h>
int main()
{
    for (int i = 0; ; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (x==y)
        {
            break;
        }
        else if (x>y)
        {
            printf("Decrescente\n");
        }
        else{
            printf("Crescente\n");
        }
    }
    
    return 0;
}