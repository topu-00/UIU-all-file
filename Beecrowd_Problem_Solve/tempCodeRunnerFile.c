#include <stdio.h>
int work(float x, float n)
{
    float result;
    return result = x / n;
}
int main()
{
    float n;
    scanf("%f", &n);
    float noate = n * 100;
    int noat = noate;
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", work(noat, 100 * 100));
    noat %= 100 * 100;
    printf("%d nota(s) de R$ 50.00\n", work(noat, 50 * 100));
    noat %= 50 * 100;
    printf("%d nota(s) de R$ 20.00\n", work(noat, 20 * 100));
    noat %= 20 * 100;
    printf("%d nota(s) de R$ 10.00\n", work(noat, 10 * 100));
    noat %= 10 * 100;
    printf("%d nota(s) de R$ 5.00\n", work(noat, 5 * 100));
    noat %= 5 * 100;
    printf("%d nota(s) de R$ 2.00\n", work(noat, 2 * 100));
    noat %= 2 * 100;
    printf("MOEDAS:\n");
     printf("%d moeda(s) de R$ 1.00\n", work(noat, 1 * 100));
    noat %= 1* 100;
    printf("%d moeda(s) de R$ 0.50\n", work(noat, 0.50 * 100));
    noat %=(int)(0.50 * 100);
    printf("%d moeda(s) de R$ 0.25\n", work(noat, 0.25 * 100));
    noat %=(int)(0.25 * 100);
    printf("%d moeda(s) de R$ 0.10\n", work(noat, 0.10 * 100));
    noat %= (int)(0.10 * 100);
    printf("%d moeda(s) de R$ 0.05\n", work(noat, 0.05 * 100));
    noat %=(int)(0.05 * 100);
    printf("%d moeda(s) de R$ 0.01\n", work(noat, 0.01 * 100));
    //noat %=(int)(0.01 * 100);
    return 0;
}