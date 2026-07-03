#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct tenant
{
    char apartment_number[100];
    char name[100];
    char occupation[100];
    char member[10];
    char year[10];
    char phone[15];
    char payment[10];
};
int main()
{
    FILE *file;
    FILE *temp;
    struct tenant tenant2[100];

    file = fopen("data.txt", "r");

    for (int i = 0; i < 100; i++)
    {
        fgets(tenant2[i].apartment_number, 100, file);
        fgets(tenant2[i].name, 100, file);
        fgets(tenant2[i].occupation, 100, file);
        fgets(tenant2[i].member, 10, file);
        fgets(tenant2[i].year, 10, file);
        fgets(tenant2[i].phone, 15, file);
        fgets(tenant2[i].payment, 10, file);
    }
    fclose(file);

    char Search_aprt[100];
    fflush(stdin);

    printf("\nEnter an Apartment to Update Payment status: ");
jump10:
    fgets(Search_aprt, 100, stdin);
    int valid_input;
    valid_input = atoi(Search_aprt);
    if (valid_input == 0)
    {

        int flag = 0;
        int index;
        for (int i = 0; i < 100; i++)
        {
            if (strcmp(Search_aprt, tenant2[i].apartment_number) == 0)
            {
                flag = 1;
                index = i;
                break;
            }
        }
        if (flag == 1)
        {
            printf("\nChange Status(Yes or No): ");
            fgets(tenant2[index].payment, 100, stdin);
        }
        else
        {
            printf("\nApartment Empty!\n\n");
            int option;
            printf("1.Update Again.\n2.Exit.\n");
            scanf("%d", &option);
            fflush(stdin);
            if (option == 1)
            {
                printf("\nPlease enter an occupied Apartment: ");
                goto jump10;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        printf("\nApartment name can only start with a letter !\n\nEnter a Valid Apartment:");
        goto jump10;
    }

    int empty_ch = 0;

    for (int i = 0; i < 100; i++)
    {
        empty_ch++;
        if (strcmp(tenant2[i].apartment_number, "") == 0)
        {
            break;
        }
    }

    temp = fopen("temp.txt", "w");
    for (int i = 0; i < empty_ch; i++)
    {
        fprintf(file, "%s", tenant2[i].apartment_number);
        fprintf(file, "%s", tenant2[i].name);
        fprintf(file, "%s", tenant2[i].occupation);
        fprintf(file, "%s", tenant2[i].member);
        fprintf(file, "%s", tenant2[i].year);
        fprintf(file, "%s", tenant2[i].phone);
        fprintf(file, "%s", tenant2[i].payment);
    }
    fclose(temp);

    if (rename("temp.txt", "data.txt") == 0)
    {
        printf("\nUpdated successfully.\n\n");
    }
    return 0;
}