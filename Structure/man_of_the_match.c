#include <stdio.h>
#include <string.h>
#include <limits.h>
#define n 2
struct player
{
    char name[100];
    char country[100];
    int run[3];
    int wicket[3];
    int point[3];
};
typedef struct player plr;
int main()
{
    plr p[n];
    printf("-----InPut-----\n");
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Nmae: ");
        fgets(p[i].name, 100, stdin);
        p[i].name[strcspn(p[i].name, "\n")] = '\0';
        printf("Country: ");
        fgets(p[i].country, 100, stdin);
        p[i].country[strcspn(p[i].country, "\n")] = '\0';
        printf("Enter the run of three match: \n");
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &p[i].run[j]);
        }
        printf("Enter the run of three match: \n");
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &p[i].wicket[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (p[i].run[j] <= 25)
            {
                p[i].point[j] = 5;
            }
            else if (p[i].run[j] > 25 && p[i].run[j] <= 50)
            {
                p[i].point[j] = 10;
            }
            else if (p[i].run[j] > 50 && p[i].run[j] <= 75)
            {
                p[i].point[j] = 15;
            }
            else if (p[i].run[j] > 75)
            {
                p[i].point[j] = 20;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            p[i].point[j] += p[i].wicket[j] * 12;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Match %d:\n", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("%s point: %d\n", p[j].name, p[j].point[i]);
        }
        for (int k = 0; k < 1; k++)
        {
            if (p[k].point[i] > p[k + 1].point[i])
            {
                printf("MOM : %s\n", p[k].name);
            }
            else
            {
                printf("MOM : %s\n", p[k + 1].name);
            }
        }
        printf("\n");
    }
    int total_point_P[2] = {0, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            total_point_P[i] += p[i].point[j];
        }
    }
    if (total_point_P[0] > total_point_P[1])
    {
        printf("Man of the Series: %s\n", p[0].name);
    }
    else
    {
        printf("Man of the Series: %s\n", p[1].name);
    }
    return 0;
}