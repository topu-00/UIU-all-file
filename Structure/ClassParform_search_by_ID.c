#include <stdio.h>
#include <string.h>
#include <limits.h>
#define n 2
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
    plr p[n];
    printf("-----InPut-----\n");
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
    int id;
    int yes = 1;
    int count = 0;
    for (int i = 0; yes == 1; i++)
    {
        printf("\nSearch ID: ");
        scanf("%d", &id);
        for (int i = 0; i < n; i++)
        {
            if (id == p[i].id)
            {
                printf("\n\n-----OutPut-----\n\n");
                printf("Player: %d\n", i + 1);
                printf("Name: ");
                printf("%s", p[i].name);
                printf("ID: %d\n", p[i].id);
                printf("Date of Birth: %d/%d/%d\n", p[i].DoB.day, p[i].DoB.month, p[i].DoB.year);
                printf("Type: %d\n", p[i].type);
                printf("KIP: %.2f\n", p[i].kpi);
                printf("\n");
                count++;
            }
        }
        if (count == 0)
        {
            printf("\n\n-----OutPut-----\n\n");
            printf("ID Not Found!\n");
        }
        count=0;
        printf("\n-----InPut-----\n");
        printf("Do You Want to search again?\n");
        printf("Enter 1 for 'YES'.\n");
        printf("Enter 2 for 'NO'.\n");
        printf("Enter Your Input: ");
        scanf("%d", &yes);
        if (yes == 1)
        {
            continue;
        }
        else if (yes == 2)
        {
            printf("\n\n-----OutPut-----\n\n");
            printf("\tThank You.\n");
            return 0;
        }
        else if (yes != 1)
        {
            printf("\n\n-----OutPut-----\n\n");
            printf("Not a Valid Input!\n");
            return 0;
        }
        count=0;
    }
    return 0;
}