#include<stdio.h>
int main()
{
    float am,coin;
    int amnt;
    int arr[6]={100,50,20,10,5,2};
    printf("Enter a Amount: ");
    scanf("%f",&am);
    amnt=(int)am;
    coin=am-amnt;
    for (int i = 0; i < 6; i++)
    {
        printf("%d nota(s) de R$ %d.00\n",amnt/arr[i],arr[i]);
    amnt%=arr[i];
    }
    /*
    amnt*=100;
    coin+=amnt;
    printf("%d nota(s) de R$ 1.00\n",amnt/100);
    amnt%=1;
    printf("%d nota(s) de R$ 0.50\n",amnt/0.50);
    amnt%=50;
    printf("%d nota(s) de R$ 0.25\n",amnt/0.25);
    amnt%=20;
    printf("%d nota(s) de R$ 0.10\n",amnt/0.10);
    amnt%=10;
    printf("%d nota(s) de R$ 0.05\n",amnt/0.05);
    amnt%=5;
    printf("%d nota(s) de R$ 0.01\n",amnt/0.01);*/
    return 0;
}
