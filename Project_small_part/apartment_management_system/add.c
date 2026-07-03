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
    struct tenant tenant1, tenant2[100];
    printf("Apartment: ");
jump1:
    fgets(tenant1.apartment_number, 100, stdin);
    int valid_input;
    valid_input = atoi(tenant1.apartment_number);
    if (valid_input == 0)
    {

        int flag = 0;

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

        for (int i = 0; i < 100; i++)
        {
            if (strcmp(tenant1.apartment_number, tenant2[i].apartment_number) == 0)
            {
                flag = 1;
                printf("\nApartment Occupied.\n\n");
                break;
            }
        }
        if (flag == 1)
        {
            printf("Enter a Valid Apartment: ");
            goto jump1;
        }
    }
    else
    {
        printf("\nApartment name can only start with a letter.\n\nEnter a Valid Apartment: ");
        goto jump1;
    }

    printf("Name: ");
    fgets(tenant1.name, 100, stdin);
    printf("Occupation: ");
    fgets(tenant1.occupation, 100, stdin);
    printf("Member: ");
    fgets(tenant1.member, 10, stdin);
    printf("Year: ");
    fgets(tenant1.year, 10, stdin);
    fflush(stdin);
    printf("Phone: ");
    fgets(tenant1.phone, 15, stdin);
    printf("payment: ");
    fgets(tenant1.payment, 10, stdin);

    file = fopen("data.txt", "a");
    fprintf(file, "%s", tenant1.apartment_number);
    fprintf(file, "%s", tenant1.name);
    fprintf(file, "%s", tenant1.occupation);
    fprintf(file, "%s", tenant1.member);
    fprintf(file, "%s", tenant1.year);
    fprintf(file, "%s", tenant1.phone);
    fprintf(file, "%s", tenant1.payment);
    fclose(file);
    return 0;
}