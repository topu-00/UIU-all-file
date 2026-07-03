#include<stdio.h>
int main()
{
    int n;
    int count=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    int z;
    printf("How many time player-2 Choice guess input: ");
    scanf("%d",&z);
    for (int i = 1; i <= z; i++)
    {
        int g;
        printf("Enter the guess number %d: ",i);
        scanf("%d",&g);
        if (n==g)
        {
            printf("Right, Player-2 wins!\n");
            break;
        }
        else{
            printf("Wrong, %d choice(s) left!\n",z-i);
            count++;
        }
    }
    if (z==count)
    {
        printf("Player-1 wins!\n");
    }
    
    return 0;
}
