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

    printf("        __  \n");
    printf("       //\\\\    \n");
    printf("      //  \\\\    \n");
    printf("     //    \\\\    \n");
    printf("    //      \\\\    \n");
    printf("   //        \\\\    \n");
    printf("  //          \\\\    \n");
    printf(" //            \\\\   \n");
    printf("//______________\\\\   \n");
    printf("||              ||              \033[96m Welcome to \033[0m \n");
    printf("||    _______   ||   \033[3mCELESTIAL HEIGHTS Apartment Complex\033[0m\n");
    printf("||    ||   ||   ||            \033[93mYour Dream Home!\033[0m\n");
    printf("||    ||   ||   ||  \n");
    printf("||____||___||___||  \n");
    printf("\n");

    int option1, upd_v_c = 0;
loop0:
    fflush(stdin);
    printf("\n\n1.Add Tenant.\n2.Remove Tenant.\n3.Tenant's Details.\n4.Update Payment.\n5.All Tenant Sorted List.\n");
    printf("\nChoose an option: ");
loop1:
    fflush(stdin);
    scanf("%d", &option1);
    fflush(stdin);
    if (option1 == 1)
    {
        // Add Start
        fflush(stdin);
    loop:
        printf("\nApartment: ");
    jump1:
        fflush(stdin);
        fgets(tenant1.apartment_number, 100, stdin);
        fflush(stdin);
        int valid_input;
        valid_input = atoi(tenant1.apartment_number);
        if (valid_input == 0)
        {

            int flag = 0;

            file = fopen("data.txt", "r");

            for (int i = 0; i < 100; i++)
            {
                fflush(stdin);
                fgets(tenant2[i].apartment_number, 100, file);
                fflush(stdin);
                fgets(tenant2[i].name, 100, file);
                fflush(stdin);
                fgets(tenant2[i].occupation, 100, file);
                fflush(stdin);
                fgets(tenant2[i].member, 10, file);
                fflush(stdin);
                fgets(tenant2[i].year, 10, file);
                fflush(stdin);
                fgets(tenant2[i].phone, 15, file);
                fflush(stdin);
                fgets(tenant2[i].payment, 10, file);
                fflush(stdin);
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
                fflush(stdin);
                goto jump1;
            }
        }
        else
        {
            printf("\nApartment name can only start with a letter.\n\nEnter a Valid Apartment: ");
            fflush(stdin);
            goto jump1;
        }

        printf("\nName: ");
        fgets(tenant1.name, 100, stdin);
        printf("Occupation: ");
        fgets(tenant1.occupation, 100, stdin);
        printf("Member: ");
        fgets(tenant1.member, 10, stdin);
        printf("Renting Since: ");
        fgets(tenant1.year, 10, stdin);
        fflush(stdin);
        printf("Phone: ");
        fgets(tenant1.phone, 15, stdin);
        printf("Payment: ");
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

        // counting start
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
        int family_count = 0;
        for (int i = 0; i < 100; i++)
        {
            if (strcmp(tenant2[i].apartment_number, "") == 0)
            {
                break;
            }
            family_count++;
        }
        printf("\nAvailable Apartments: %d\n", 100 - family_count);
        // counting End
        int option3;
        printf("\n1.Main Menu.\n2.Add Another Tenant\n3.Exit.\n");
        fflush(stdin);
        scanf("%d", &option3);
        fflush(stdin);

        if (option3 == 1)
        {
            fflush(stdin);
            goto loop0;
        }

        else if (option3 == 2)
        {
            fflush(stdin);
            goto loop;
        }

        else
        {
            printf("\n\n\033[96m----Thank You----\n\n\033[0m");
            return 0;
        }

        // add End;
    }

    else if (option1 == 2)
    {
        // remove Start
        fflush(stdin);
    jump:
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

    jump3:
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
                fflush(stdin);
                goto jump3;
            }
        }
        else
        {
            printf("\nApartment name can only start with a letter.\n\nEnter a Valid Apartment:");
            fflush(stdin);
            goto jump3;
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
            printf("\nRemoved successfully.\n");
        }

        // counting start
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
        int family_count = 0;
        for (int i = 0; i < 100; i++)
        {
            if (strcmp(tenant2[i].apartment_number, "") == 0)
            {
                break;
            }
            family_count++;
        }
        printf("\nAvailable Apartments: %d\n", 100 - family_count);
        // counting End

        int option4;
        printf("\n1.Main Menu.\n2.Remove Another Tenant.\n3.Exit.\n");
        fflush(stdin);
        scanf("%d", &option4);
        fflush(stdin);
        if (option4 == 1)
        {
            fflush(stdin);
            goto loop0;
            // main menu;
        }
        else if (option4 == 2)
        {
            fflush(stdin);
            goto jump;
            // remove
        }
        else
        {
            printf("\n\n\033[96m----Thank You----\n\n\033[0m");
            return 0;
        }
        // remove End;
    }

    else if (option1 == 3)
    {
        // search start;
        fflush(stdin);
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
    jumpy:
        fflush(stdin);
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
                    printf("\nApartment Empty !\n\n");
                    int option;
                    printf("1.Search Again.\n2.Exit.\n\n");
                    fflush(stdin);
                    scanf("%d", &option);
                    fflush(stdin);
                    if (option == 1)
                    {
                        printf("Please enter an occupied Apartment: ");
                        fflush(stdin);
                        goto jumpx;
                    }
                    else
                    {
                        printf("\n\n\033[96m----Thank You----\n\n\033[0m");
                        return 0;
                    }
                }
            }
            else
            {
                printf("\nApartment name can only start with a letter !\n\nEnter a Valid Apartment:");
                goto jumpx;
            }
            int option4;
            printf("\n1.Main Menu.\n2.Exit.\n");
            fflush(stdin);
            scanf("%d", &option4);
            fflush(stdin);
            if (option4 == 1)
            {
                fflush(stdin);
                goto loop0;
                // main menu;
            }
            else
            {
                printf("\n\n\033[96m----Thank You----\n\n\033[0m");
                return 0;
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

            int option4;
            printf("\n1.Main Menu.\n2.Exit.\n");
            fflush(stdin);
            scanf("%d", &option4);
            fflush(stdin);
            if (option4 == 1)
            {
                fflush(stdin);
                goto loop0;
                // main menu;
            }
            else
            {
                printf("\n\n\033[96m----Thank You----\n\n\033[0m");
                return 0;
            }
        }

        else
        {
            printf("\nInvalid Input !\n\nEnter a Valid Input: ");
            fflush(stdin);
            goto jumpy;
        }

        // search End;
    }

    else if (option1 == 4)
    {
        // update payment Start;
        fflush(stdin);
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
    jump101:
        printf("\nEnter an Apartment to Update Payment status: ");
    jump10:
        fflush(stdin);
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
                fflush(stdin);
                fgets(tenant2[index].payment, 100, stdin);
                fflush(stdin);
            }
            else
            {
                printf("\nApartment Empty!\n\n");
                int option;
                printf("1.Update Again.\n2.Exit.\n");
                fflush(stdin);
                scanf("%d", &option);
                fflush(stdin);
                if (option == 1)
                {
                    printf("\nPlease enter an occupied Apartment: ");
                    fflush(stdin);
                    goto jump10;
                }
                else
                {
                    printf("\n\n\033[96m----Thank You----\n\n\033[0m");
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

        int option3;
        printf("\n1.Main Menu.\n2.Update Another Tenant's Payment Status.\n3.Exit.\n");
        fflush(stdin);
        scanf("%d", &option3);
        fflush(stdin);

        if (option3 == 1)
        {
            fflush(stdin);
            goto loop0;
        }

        else if (option3 == 2)
        {
            fflush(stdin);
            goto jump101;
        }

        else
        {
            printf("\n\n\033[96m----Thank You----\n\n\033[0m");
            return 0;
        }

        // update payment End;
    }

    else if (option1 == 5)
    {
        // sorting start;
        fflush(stdin);
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

        int option4;
        printf("\n1.Main Menu.\n2.Exit.\n");
        fflush(stdin);
        scanf("%d", &option4);
        fflush(stdin);
        if (option4 == 1)
        {
            fflush(stdin);
            goto loop0;
            // main menu;
        }
        else
        {
            printf("\n\n\033[96m----Thank You----\n\n\033[0m");
            return 0;
        }

        // sorting End;
    }

    else
    {
        upd_v_c++;
        if (upd_v_c == 3)
        {
            printf("\n\033[31mOops ! You Can't Try again.\n\n\033[0m");
            return 0;
        }

        printf("Enter a Valid Input: ");
        goto loop1;
    }
    return 0;
}