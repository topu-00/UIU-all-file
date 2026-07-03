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
    struct tenant tenant2[1000], tenant1;
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

    printf("\nEnter Apartment to remove: ");

jump1:
    fgets(tenant1.apartment_number, 100, stdin);
    int valid_input;
    valid_input = atoi(tenant1.apartment_number);
    if (valid_input == 0)
    {

        int flag = 0;

        for (int i = 0; i < 100; i++)
        {
            if (strcmp(tenant1.apartment_number, tenant2[i].apartment_number) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            for (int i = 0; i < 100; i++)
            {
                if (strcmp(tenant1.apartment_number, tenant2[i].apartment_number) == 0)
                {
                    for (int j = i; j < 100; j++)
                    {
                        tenant2[j] = tenant2[j + 1];
                    }
                }
            }
        }
        else if (flag == 0)
        {
            printf("\nApartment Already Empty !\n\n");
            printf("Search an Occupied Apartment: ");
            goto jump1;
        }
    }
    else
    {
        printf("\nApartment name can only start with a letter.\n\nEnter a Valid Apartment:");
        goto jump1;
    }

    temp = fopen("temp.txt", "w");
    for (int i = 0; i < 100; i++)
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
        printf("Removed successfully.\n");
    }
    else
    {
        printf("Can't remove family\n");
    }

    return 0;
}