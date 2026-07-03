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
    printf("\nApartment Renting Period in Descending Order: \n\n");
    for (int i = 0; i < 100; i++)
    {
        tenant2[i].apartment_number[strcspn(tenant2[i].apartment_number, "\n")] = '\0';
        tenant2[i].name[strcspn(tenant2[i].name, "\n")] = '\0';

        if (strcmp(tenant2[i].apartment_number, "") == 0)
        {
            break;
        }
        printf("%d.%s -> %s\n", i + 1, tenant2[i].apartment_number, tenant2[i].name);
    }
    printf("\n");
    return 0;
}