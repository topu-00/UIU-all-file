#include <stdio.h>
#include <string.h>
#include <limits.h>
#define n 11
struct age
{
    int day;
    int month;
    int year;
};
struct player
{
    int id;
    char name[100];
    int type;
    float kpi;
    struct age DoB;
};
typedef struct player plr;
int main()
{
    plr p[n], p1;
    printf("\n\n-----InPut-----\n\n");
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Nmae: ");
        fgets(p[i].name, 100, stdin);
        printf("ID: ");
        scanf("%d", &p[i].id);
        printf("Dath of Birth(Day/Month/Year): ");
        scanf("%d %d  %d", &p[i].DoB.day, &p[i].DoB.month, &p[i].DoB.year);
        printf("Type(1/2/3/4): ");
        scanf("%d", &p[i].type);
        printf("KPI: ");
        scanf("%f", &p[i].kpi);
    }
    float max_kpi = INT_MIN;
    int index = -1;
    for (int j = 0; j < n; j++)
    {
        for (int i = j; i < n; i++)
        {
            if (p[i].kpi > max_kpi)
            {
                max_kpi = p[i].kpi;
                index = i;
            }
        }
        p1 = p[j];
        p[j] = p[index];
        p[index] = p1;
        max_kpi = INT_MIN;
    }
    printf("\n\n-----OutPut-----\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Player: %d\n", i + 1);
        printf("Name: ");
        printf("%s", p[i].name);
        printf("ID: %d\n", p[i].id);
        printf("Date of Birth: %d/%d/%d\n", p[i].DoB.day, p[i].DoB.month, p[i].DoB.year);
        printf("Type: %d\n", p[i].type);
        printf("KIP: %.2f\n", p[i].kpi);
        printf("\n\n");
    }
    return 0;
}