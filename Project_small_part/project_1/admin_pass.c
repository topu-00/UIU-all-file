// all done final_NULL;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100
// Define color codes
#define END "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"
struct email_pass
{
    char email[size];
    char pass[size];
};

int main()
{
    FILE *pass;
    int person_count = 0;
    struct email_pass person1, person[10000];
login:
    pass = fopen("passWord.txt", "r");

    if (pass == NULL)
    {
        printf("Error Opening PassWord r File 1\n");
    }

    else
    {

        for (int i = 0; i < 10000; i++)
        {
            fgets(person[i].email, size, pass);
            fgets(person[i].pass, size, pass);
            if (strcmp(person[i].email, "") == 0)
            {
                break;
            }
            person_count++;
        }
        fclose(pass);
    }
    printf(CYAN "\n----Login----\n\n" END);
    printf("Email: ");
    fgets(person1.email, size, stdin);

    printf("PassWord: ");
    fgets(person1.pass, 100, stdin);

    int person_check = 0;
    for (int i = 0; i < person_count; i++)
    {
        if ((strcmp(person[i].email, person1.email) == 0) && (strcmp(person[i].pass, person1.pass)) == 0)
        {
            person_check = 1;
            break;
        }
    }

    if (person_check == 1)
    {
        printf("Access\n"); // add,delete,detail,
    }

    else
    {
        int option;
        printf(YELLOW "\n1.Create a Account.\n2.Try again.\n3.Exit.\n" END);
        scanf("%d", &option);

        if (option == 1)
        {
            fflush(stdin);
            printf(GREEN "-----Create your Account-----\n\n" END);

            printf("Email: ");
            fgets(person1.email, size, stdin);

            printf("PassWord: ");
            fgets(person1.pass, 100, stdin);

            pass = fopen("passWord.txt", "a");
            if (pass == NULL)
            {
                printf("Error Opening PassWord a File 1\n");
            }

            fputs(person1.email, pass);
            fputs(person1.pass, pass);
            fclose(pass);

            int login_option;
            printf(MAGENTA "\n1.Login Page.\n2.Exit.\n" END);
            scanf("%d", &login_option);
            if (login_option == 1)
            {
                fflush(stdin);
                goto login;
            }
            else
            {
                printf(MAGENTA "\n-----Thank You-----\n\n" END);
                return 0;
            }
        }

        else if (option == 2)
        {
            fflush(stdin);
            goto login;
        }

        else
        {
            printf(MAGENTA "\n-----Thank You-----\n\n" END);
            return 0;
        }
    }

    return 0;
}