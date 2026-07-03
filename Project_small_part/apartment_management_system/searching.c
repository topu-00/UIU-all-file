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
    int option;
    printf("\n1.Show Individual Apartment Information.\n2.Show All Apartment Information.\n");
    scanf("%d", &option);
    fflush(stdin);
    if (option == 1)
    {

        printf("\nEnter an Apartment to Know Information:");
    jumpx:
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
                printf("\n");
                printf("Apartment: %s", tenant2[index].apartment_number);
                printf("Name: %s", tenant2[index].name);
                printf("Occupation: %s", tenant2[index].occupation);
                printf("Members: %s", tenant2[index].member);
                printf("Renting Since: %s", tenant2[index].year);
                printf("Contact Number: %s", tenant2[index].phone);
                printf("Payment Status: %s", tenant2[index].payment);
                printf("\n");
            }
            else
            {
                printf("\nApartment Empty!\n\n");
                int option;
                printf("1.Search Again.\n2.Exit.\n\n");
                scanf("%d", &option);
                fflush(stdin);
                if (option == 1)
                {
                    printf("Please enter an occupied Apartment: ");
                    goto jumpx;
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
            goto jumpx;
        }
    }
    else if (option == 2)
    {
        for (int i = 0; i < 100; i++)
        {
            if (strcmp(tenant2[i].apartment_number, "") == 0)
            {
                break;
            }
            printf("\n");
            printf("Apartment: %s", tenant2[i].apartment_number);
            printf("Name: %s", tenant2[i].name);
            printf("Occupation: %s", tenant2[i].occupation);
            printf("Member: %s", tenant2[i].member);
            printf("Renting Since: %s", tenant2[i].year);
            printf("Contact Number: %s", tenant2[i].phone);
            printf("Payment Status: %s", tenant2[i].payment);
            printf("\n");
        }
    }
    else
    {
        return 0;
    }
    return 0;
}