#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100
struct medi
{
    char name[100];
    char gName[100];
    char type[100];
    char company[100];
    char price[100];
};
int main()
{
    struct medi med[5000];
    FILE *file;
    file = fopen("file.txt", "r");
    for (int i = 0; i < 5000; i++)
    {
        fgets(med[i].name, size, file);
        fgets(med[i].gName, size, file);
        fgets(med[i].type, size, file);
        fgets(med[i].company, size, file);
        fgets(med[i].price, size, file);
        if (strcmp(med[i].name, "") == 0)
        {
            break;
        }
    }
    fclose(file);

    int option;

    printf("\n1.Brand.\n2.GENERIC NAME.\n");
jump:
    scanf("%d", &option);
    fflush(stdin);
    if (option == 1)
    {
        char name2[size];
        int index;
        int check = 0;
    jump1:
        printf("\nSearch Name(Start With Capitale latter): ");
        fgets(name2, size, stdin);
        fflush(stdin);
        for (int i = 0; i < 5000; i++)
        {
            if (strcmp(name2, med[i].name) == 0)
            {
                index = i;
                check = 1;
                break;
            }
            else if (strcmp(med[i].name, "") == 0)
            {
                break;
            }
        }
        if (check == 1)
        {
            printf("\nName     : %s", med[index].name);
            printf("\nGENERIC  : %s", med[index].gName);
            printf("\nType     : %s", med[index].type);
            printf("\nCompany  : %s", med[index].company);
            printf("\nPrice    : %s\n\n", med[index].price);
        }
        else
        {
            printf("\nNot Found !\n\n");
        }
        int optionM;
        printf("\n1.Search Again.\n2.Exit.\n");
        scanf("%d", &optionM);
        fflush(stdin);
        if (optionM == 1)
        {
            fflush(stdin);
            goto jump1;
        }
        else
        {
            printf("\n\n-----Thank You-----\n\n");
            return 0;
        }
    }
    else if (option == 2)
    {
        char name3[size];
        int index3;
        int check3 = 0;
    jump2:
        printf("\nSearch GENERAC Name(Start With Capitale latter): ");
        fgets(name3, size, stdin);
        fflush(stdin);
        for (int i = 0; i < 5000; i++)
        {
            if (strcmp(name3, med[i].gName) == 0)
            {
                index3 = i;
                check3 = 1;
                if (check3 == 1)
                {
                    printf("\nName     : %s", med[index3].name);
                    printf("\nGENERIC  : %s", med[index3].gName);
                    printf("\nType     : %s", med[index3].type);
                    printf("\nCompany  : %s", med[index3].company);
                    printf("\nPrice    : %s\n\n", med[index3].price);
                }
            }
            else if (strcmp(med[i].name, "") == 0)
            {
                break;
            }
        }
        if (check3 == 0)
        {
            printf("\nNot Found !\n\n");
        }
        int optionG;
        printf("\n1.Search Again.\n2.Exit.\n");
        scanf("%d", &optionG);
        fflush(stdin);
        if (optionG == 1)
        {
            fflush(stdin);
            check3 = 0;
            goto jump2;
        }
        else
        {
            printf("\n\n-----Thank You-----\n\n");
            return 0;
        }
    }
    else
    {
        printf("Invalid Input !\n\n");
        printf("Try Again.\n\n");
        fflush(stdin);
        goto jump;
    }
    return 0;
}
